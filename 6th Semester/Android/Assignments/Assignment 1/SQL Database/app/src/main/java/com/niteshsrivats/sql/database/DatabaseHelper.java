package com.niteshsrivats.sql.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

/**
 * @author Nitesh (niteshsrivats.k@gmail.com)
 */

public class DatabaseHelper extends SQLiteOpenHelper {
    private String tableName;
    private String createQuery;


    public DatabaseHelper(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version, String tableName, String createQuery) {
        super(context, name, factory, version);
        this.tableName = tableName;
        this.createQuery = createQuery;
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL(this.createQuery);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        sqLiteDatabase.execSQL("DROP TABLE IF EXISTS " + tableName);
        onCreate((sqLiteDatabase));
    }

    public boolean insertData(ContentValues contentValues) {
        SQLiteDatabase db = this.getWritableDatabase();
        long result = db.insert(this.tableName, null, contentValues);
        return result != -1;
    }

    public boolean updateData(ContentValues contentValues) {
        SQLiteDatabase db = this.getWritableDatabase();
        int result = db.update(this.tableName, contentValues, "usn=?", (String[]) contentValues.get("usn"));
        return result != -1;
    }

    public Cursor getAll() {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.rawQuery("SELECT * FROM " + this.tableName, null);
    }

    public Boolean deleteData(String usn) {
        SQLiteDatabase db = this.getWritableDatabase();
        int result = db.delete(this.tableName, "usn=?", new String[]{usn});
        return result != -1;
    }
}
