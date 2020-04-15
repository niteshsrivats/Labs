package com.niteshsrivats.external.storage;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private EditText text;
    private File file;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.requestPermissions(
                new String[]{Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE},
                1
        );
        // For external storage (SD card) File path = getBaseContext().getExternalFilesDir(null);
        file = new File (getBaseContext().getFilesDir(), "demo.txt");

        text = findViewById(R.id.text);
        Button buttonRead = findViewById(R.id.buttonRead);
        Button buttonWrite = findViewById(R.id.buttonWrite);
        Button buttonClear = findViewById(R.id.buttonClear);
        buttonClear.setOnClickListener(this);
        buttonRead.setOnClickListener(this);
        buttonWrite.setOnClickListener(this);

        try {
            boolean created = file.createNewFile();
        } catch (IOException e) {
            Toast.makeText(this, e.getMessage(), Toast.LENGTH_LONG).show();
        }
    }

    private void writeToFile(String text) {
        if (this.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED) {
            try {
                Files.write(Paths.get(file.getPath()), text.getBytes());
                Toast.makeText(this, "Write successful.", Toast.LENGTH_LONG).show();
            } catch (IOException e) {
                Toast.makeText(this, e.getMessage(), Toast.LENGTH_LONG).show();
            }
        } else {
            Toast.makeText(this, "Permission to write to storage required.", Toast.LENGTH_LONG).show();
        }
    }

    private String readFromFile() {
        if (this.checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED) {
            try {
                String text = new String(Files.readAllBytes(Paths.get(file.getPath())), StandardCharsets.UTF_8);
                Toast.makeText(this, "Read successful.", Toast.LENGTH_LONG).show();
                return text;
            } catch (IOException e) {
                Toast.makeText(this, e.getMessage(), Toast.LENGTH_LONG).show();
            }
        } else {
            Toast.makeText(this, "Permission to read from storage required.", Toast.LENGTH_LONG).show();
        }
        return null;
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.buttonRead:
                text.setText(readFromFile());
                break;
            case R.id.buttonWrite:
                writeToFile(text.getText().toString());
                break;
            case R.id.buttonClear:
                text.setText(null);
                break;
            default:
                throw new IllegalStateException("Unexpected value: " + view.getId());
        }
    }
}
