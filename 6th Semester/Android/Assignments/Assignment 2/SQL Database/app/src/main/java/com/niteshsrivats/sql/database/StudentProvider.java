package com.niteshsrivats.sql.database;

import android.content.ContentProvider;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Context;
import android.content.UriMatcher;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteQueryBuilder;
import android.net.Uri;
import android.text.TextUtils;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.HashMap;
import java.util.Objects;

/**
 * @author Nitesh (niteshsrivats.k@gmail.com)
 */

public class StudentProvider extends ContentProvider {

    static final String PROVIDER_NAME = "com.niteshsrivats.sql.database.StudentProvider";
    static final Uri CONTENT_URI = Uri.parse("content://" + PROVIDER_NAME + "/students");

    static final String ROLL_NO = "rollno";
    static final String NAME = "name";
    static final String MARKS = "marks";
    static final int STUDENTS = 1;
    static final int STUDENTS_ID = 2;

    static final UriMatcher uriMatcher;

    static {
        uriMatcher = new UriMatcher(UriMatcher.NO_MATCH);
        uriMatcher.addURI(PROVIDER_NAME, "students", STUDENTS);
        uriMatcher.addURI(PROVIDER_NAME, "students/#", STUDENTS_ID);
    }

    private static HashMap<String, String> STUDENTS_PROJECTION_MAP;
    private final String TABLE_NAME = "students";
    private SQLiteDatabase db;


    private static class DatabaseHelper extends SQLiteOpenHelper {
        DatabaseHelper(@Nullable Context context, @Nullable String name,
                       @Nullable SQLiteDatabase.CursorFactory factory, int version) {
            super(context, name, factory, version);
        }

        @Override
        public void onCreate(SQLiteDatabase sqLiteDatabase) {
            sqLiteDatabase.execSQL(
                    "CREATE TABLE IF NOT EXISTS students(rollno VARCHAR PRIMARY KEY, name " +
                            "VARCHAR, marks VARCHAR)");
        }

        @Override
        public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
            sqLiteDatabase.execSQL("DROP TABLE IF EXISTS students");
            onCreate((sqLiteDatabase));
        }
    }

    @Override
    public boolean onCreate() {
        DatabaseHelper helper = new DatabaseHelper(getContext(), "studentsDB", null, 1);
        db = helper.getWritableDatabase();
        return db != null;
    }

    @Nullable
    @Override
    public Cursor query(@NonNull Uri uri, @Nullable String[] projection,
                        @Nullable String whereClause,
                        @Nullable String[] whereArgs, @Nullable String sortOrder) {
        SQLiteQueryBuilder queryBuilder = new SQLiteQueryBuilder();
        queryBuilder.setTables(TABLE_NAME);
        switch (uriMatcher.match(uri)) {
            case STUDENTS:
                queryBuilder.setProjectionMap(STUDENTS_PROJECTION_MAP);
                break;
            case STUDENTS_ID:
                queryBuilder.appendWhere(ROLL_NO + "=" + uri.getPathSegments().get(1));
                break;
        }
        if (sortOrder == null || Objects.equals(sortOrder, "")) {
            sortOrder = NAME;
        }

        Cursor c = queryBuilder.query(db, projection, whereClause, whereArgs, null, null, sortOrder);
        c.setNotificationUri(Objects.requireNonNull(getContext()).getContentResolver(), uri);
        return c;
    }

    @Nullable
    @Override
    public String getType(@NonNull Uri uri) {
        return null;
    }

    @Nullable
    @Override
    public Uri insert(@NonNull Uri uri, @Nullable ContentValues contentValues) {
        Cursor cursor = db.query(TABLE_NAME, null, ROLL_NO + "=?",
                new String[]{contentValues.get(ROLL_NO).toString()},
                null, null, null);
        if (cursor.getCount() > 0) {
            cursor.close();
            throw new SQLException("Failed to add a record into " + uri);
        }

        db.insert(TABLE_NAME, "", contentValues);
        Uri _uri = ContentUris.withAppendedId(CONTENT_URI, Long.parseLong(contentValues.get(ROLL_NO).toString()));
        Objects.requireNonNull(getContext()).getContentResolver().notifyChange(_uri, null);
        return _uri;
    }

    @Override
    public int delete(@NonNull Uri uri, @Nullable String whereClause,
                      @Nullable String[] whereArgs) {
        int count;
        switch (uriMatcher.match(uri)) {
            case STUDENTS:
                count = db.delete(TABLE_NAME, whereClause, whereArgs);
                break;
            case STUDENTS_ID:
                String id = uri.getPathSegments().get(1);
                count = db.delete(TABLE_NAME, ROLL_NO + " = " + id + (!TextUtils.isEmpty(whereClause) ?
                        "AND (" + whereClause + ')' : ""), whereArgs);
                break;
            default:
                throw new IllegalArgumentException("Unknown URI " + uri);
        }
        Objects.requireNonNull(getContext()).getContentResolver().notifyChange(uri, null);
        return count;
    }

    @Override
    public int update(@NonNull Uri uri, @Nullable ContentValues contentValues,
                      @Nullable String whereClause, @Nullable String[] whereArgs) {
        int count;
        switch (uriMatcher.match(uri)) {
            case STUDENTS:
                count = db.update(TABLE_NAME, contentValues, whereClause, whereArgs);
                break;
            case STUDENTS_ID:
                count = db.update(TABLE_NAME, contentValues, ROLL_NO + " = " + uri.getPathSegments().get(1) +
                        (!TextUtils.isEmpty(whereClause) ? " AND (" + whereClause + ')' : ""), whereArgs);
                break;
            default:
                throw new IllegalArgumentException("Unknown URI " + uri);
        }
        Objects.requireNonNull(getContext()).getContentResolver().notifyChange(uri, null);
        return count;
    }
}
