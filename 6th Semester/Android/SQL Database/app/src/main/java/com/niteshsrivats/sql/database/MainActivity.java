package com.niteshsrivats.sql.database;

import android.app.AlertDialog.Builder;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements OnClickListener {
    private EditText rollNo, name, marks;
    private Button insert, delete, update, viewOne, viewAll;
    private SQLiteDatabase db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        rollNo = findViewById(R.id.rollNo);
        name = findViewById(R.id.name);
        marks = findViewById(R.id.marks);
        insert = findViewById(R.id.buttonInsert);
        delete = findViewById(R.id.buttonDelete);
        update = findViewById(R.id.buttonUpdate);
        viewOne = findViewById(R.id.buttonView);
        viewAll = findViewById(R.id.buttonViewAll);

        insert.setOnClickListener(this);
        delete.setOnClickListener(this);
        update.setOnClickListener(this);
        viewOne.setOnClickListener(this);
        viewAll.setOnClickListener(this);

        db = openOrCreateDatabase("studentDB", Context.MODE_PRIVATE, null);
        db.execSQL("CREATE TABLE IF NOT EXISTS student(rollno VARCHAR, name VARCHAR, marks VARCHAR);");

    }

    public void showMessage(String title, String message) {
        Builder builder = new Builder(this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.show();
    }

    public void clearText() {
        rollNo.setText(null);
        name.setText(null);
        marks.setText(null);
        rollNo.requestFocus();
    }

    public boolean isBlank(String string) {
        return string == null || string.trim().length() == 0;
    }


    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.buttonInsert:
                if (isBlank(rollNo.getText().toString()) || isBlank(name.getText().toString()) || isBlank(marks.getText().toString())) {
                    showMessage("Error", "Please enter all values.");
                } else {
                    db.execSQL(String.format("INSERT INTO student VALUES ('%s','%s','%s');", rollNo.getText(), name.getText(), marks.getText()));
                    showMessage("Success", "Record added.");
                    clearText();
                }
                break;

            case R.id.buttonDelete:
                if (isBlank(rollNo.getText().toString())) {
                    showMessage("Error", "Please enter Roll Number.");
                } else {
                    Cursor c = db.rawQuery(String.format("SELECT * FROM student WHERE rollno = '%s'", rollNo.getText()), null);
                    if (c.moveToFirst()) {
                        db.execSQL(String.format("DELETE FROM student WHERE rollno='%s'", rollNo.getText()));
                        showMessage("Success", "Record Deleted");
                        clearText();
                    } else {
                        showMessage("Error", "Invalid Roll Number.");
                    }
                    c.close();
                }
                break;

            case R.id.buttonUpdate:
                if (isBlank(rollNo.getText().toString())) {
                    showMessage("Error", "Please enter Roll Number.");
                } else {
                    Cursor c = db.rawQuery(String.format("SELECT * FROM student WHERE rollno='%s'", rollNo.getText()), null);
                    if (c.moveToFirst()) {
                        db.execSQL(String.format("UPDATE student SET name='%s', marks='%s' WHERE rollno='%s'", name.getText(), marks.getText(), rollNo.getText()));
                        showMessage("Success", "Record modified.");
                        clearText();
                    } else {
                        showMessage("Error", "Invalid Roll Number.");
                    }
                    c.close();
                }
                break;

            case R.id.buttonView:
                if (isBlank(rollNo.getText().toString())) {
                    showMessage("Error", "Please enter Roll Number.");
                } else {
                    Cursor c = db.rawQuery(String.format("SELECT * FROM student WHERE rollno='%s'", rollNo.getText()), null);
                    if (c.moveToFirst()) {
                        name.setText(c.getString(1));
                        marks.setText(c.getString(2));
                    } else {
                        showMessage("Error", "Invalid Roll Number.");
                        clearText();
                    }
                    c.close();
                }
                break;

            case R.id.buttonViewAll:
                Cursor c = db.rawQuery("SELECT * FROM student", null);
                if (c.getCount() == 0) {
                    showMessage("Error", "No records found.");
                } else {
                    StringBuilder buffer = new StringBuilder();
                    while (c.moveToNext()) {
                        buffer.append("Roll Number:\t\t").append(c.getString(0)).append("\n");
                        buffer.append("Name:\t\t").append(c.getString(1)).append("\n");
                        buffer.append("Marks:\t\t").append(c.getString(2)).append("\n\n");
                    }
                    c.close();
                    showMessage("Student Details", buffer.toString());
                }
                c.close();
                break;

            default:
                throw new IllegalStateException("Unexpected value: " + view.getId());
        }
    }
}
