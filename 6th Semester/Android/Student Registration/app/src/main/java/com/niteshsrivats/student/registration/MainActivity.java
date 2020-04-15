package com.niteshsrivats.student.registration;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private EditText name, usn, email, phoneNumber;
    private TextView error;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        name = findViewById(R.id.nameField);
        usn = findViewById(R.id.usnField);
        email = findViewById(R.id.emailField);
        phoneNumber = findViewById(R.id.phoneNumberField);
        error = findViewById(R.id.errorsView);
        Button button = findViewById(R.id.submitButton);
        button.setOnClickListener(this);
    }

    public void onClick(View v) {
        Intent intent = new Intent(this, DisplayActivity.class);
        if (checkBlank(name) || checkBlank(usn) || checkBlank(email) || checkBlank(phoneNumber)) {
            error.setText(getText(R.string.error_message));
        } else {
            error.setText(null);
            intent.putExtra("name", name.getText().toString());
            intent.putExtra("usn", usn.getText().toString());
            intent.putExtra("email", email.getText().toString());
            intent.putExtra("phoneNumber", phoneNumber.getText().toString());
            startActivity(intent);
        }
    }

    private Boolean checkBlank(TextView textView) {
        return textView.getText().length() == 0;
    }
}
