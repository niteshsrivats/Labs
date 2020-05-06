package com.niteshsrivats.sql.database;

import android.content.ContentValues;

/**
 * @author Nitesh (niteshsrivats.k@gmail.com)
 */

public class Student {
    private String rollno;
    public String name;
    private String marks;

    Student(String rollno, String name, String marks) {
        this.rollno = rollno;
        this.name = name;
        this.marks = marks;
    }

    ContentValues getContentValues() {
        ContentValues contentValues = new ContentValues();
        contentValues.put("rollno", this.rollno);
        contentValues.put("name", this.name);
        contentValues.put("marks", this.marks);
        return contentValues;
    }
}
