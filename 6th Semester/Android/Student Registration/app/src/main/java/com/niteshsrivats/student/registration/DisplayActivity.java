package com.niteshsrivats.student.registration;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class DisplayActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display);

        TextView name = findViewById(R.id.nameView);
        TextView usn = findViewById(R.id.usnView);
        TextView email = findViewById(R.id.emailView);
        TextView phoneNumber = findViewById(R.id.phoneNumberView);

        Intent i = getIntent();
        name.setText(i.getStringExtra("name"));
        usn.setText(i.getStringExtra("usn"));
        email.setText(i.getStringExtra("email"));
        phoneNumber.setText(i.getStringExtra("phoneNumber"));
    }
}
