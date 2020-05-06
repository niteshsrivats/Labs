package com.niteshsrivats.sql.database;

import android.content.ContentValues;

/**
 * @author Nitesh (niteshsrivats.k@gmail.com)
 */
public class Student {
    public String usn;
    public String name;
    public String email;

    public Student(String usn, String name, String email) {
        this.usn = usn;
        this.name = name;
        this.email = email;
    }

    public ContentValues getContentValues() {
        ContentValues contentValues = new ContentValues();
        contentValues.put("usn", this.usn);
        contentValues.put("name", this.name);
        contentValues.put("email", this.email);
        return contentValues;
    }
}
