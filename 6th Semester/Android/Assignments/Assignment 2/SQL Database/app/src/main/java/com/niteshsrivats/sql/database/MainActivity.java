package com.niteshsrivats.sql.database;

import android.app.AlertDialog.Builder;
import android.content.ContentUris;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import static com.niteshsrivats.sql.database.StudentProvider.CONTENT_URI;

public class MainActivity extends AppCompatActivity implements OnClickListener {
    private EditText rollNo, name, marks;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int[] buttons = {R.id.buttonInsert, R.id.buttonUpdate, R.id.buttonDelete, R.id.buttonView};
        for (int id : buttons) {
            Button button = findViewById(id);
            button.setOnClickListener(this);
        }

        rollNo = findViewById(R.id.rollNo);
        name = findViewById(R.id.name);
        marks = findViewById(R.id.marks);
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

//    public void UpdateStudent(View v) {
//        Log.d("BMSCE", "update1");
//        ContentValues values = new ContentValues();
//        //values.put("Name", ((EditText)findViewById(R.id.editText2)).getText().toString());
//        //String id_entered=(String)((EditText)findViewById(R.id.editText1)).getText().toString();
//        //getContentResolver().update(Uri.parse("content://com.example.umadevi.studentdbcontentprovider.myStudentDbContentProvider/student_table/"+id_entered),
//        //values,null,null);
//        int m = 10;
//        values.put("Marks", m);
//        getContentResolver().update(Uri.parse("content://com.example.umadevi.studentdbcontentprovider.myStudentDbContentProvider/student_table/"), values,
//                "Name='Aditya'", null);
//        //Log.d("BMSCE","content://com.example.umadevi.studentdbcontentprovider.myStudentDbContentProvider/student_table/"+id_entered);
//        Toast.makeText(getBaseContext(), "Record Updated", Toast.LENGTH_LONG).show();
//    }

    public boolean isBlank(EditText text) {
        String string = text.getText().toString();
        return string.trim().length() == 0;
    }

    public String getString(EditText text) {
        return text.getText().toString();
    }

    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.buttonInsert:
                if (isBlank(rollNo) || isBlank(name) || isBlank(marks)) {
                    showMessage("Error", "Please enter all values.");
                } else {
                    try {
                        getContentResolver().insert(CONTENT_URI, new Student(getString(rollNo), getString(name), getString(marks)).getContentValues());
                        showMessage("Success", "Record added.");
                        clearText();
                    } catch (Exception e) {
                        showMessage("Error", "Record already exists.");
                    }
                }
                break;

            case R.id.buttonDelete:
                if (isBlank(rollNo)) {
                    showMessage("Error", "Please enter Roll Number.");
                } else {
                    int count = getContentResolver().delete(ContentUris.withAppendedId(CONTENT_URI, Long.parseLong(getString(rollNo))),
                            null, null);
                    if (count > 0) {
                        showMessage("Success", "Record Deleted");
                        clearText();
                    } else {
                        showMessage("Error", "Record does not exist.");
                    }
                }
                break;

            case R.id.buttonUpdate:
                if (isBlank(rollNo)) {
                    showMessage("Error", "Please enter Roll Number.");
                } else {
                    int count = getContentResolver().update(CONTENT_URI,
                            new Student(getString(rollNo), getString(name), getString(marks)).getContentValues(), null, null);
                    if (count > 0) {
                        showMessage("Success", "Record modified.");
                        clearText();
                    } else {
                        showMessage("Error", "Record does not exist");
                    }

                }
                break;

            case R.id.buttonView:
                if (isBlank(rollNo)) {
                    showMessage("Error", "Please enter Roll Number.");
                } else {
                    Cursor c = getContentResolver().query(ContentUris.withAppendedId(CONTENT_URI, Long.parseLong(getString(rollNo))),
                            null, null, null, null);
                    if (c.moveToFirst()) {
                        name.setText(c.getString(1));
                        marks.setText(c.getString(2));
                    } else {
                        showMessage("Error", "Record does not exist.");
                        clearText();
                    }
                    c.close();
                }
                break;

            default:
                throw new IllegalStateException("Unexpected value: " + view.getId());
        }
    }
}
