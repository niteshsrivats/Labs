package com.niteshsrivats.gps;

import android.Manifest;
import android.content.pm.PackageManager;
import android.location.Location;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private GPS gps;
    private boolean permissionsGranted = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button buttonShowLocation = findViewById(R.id.buttonShowLocation);
        gps = new GPS(this);

        this.requestPermissions(
                new String[]{Manifest.permission.ACCESS_FINE_LOCATION},
                1
        );
        buttonShowLocation.setOnClickListener(this);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if (requestCode == 1 && (grantResults.length <= 0 || grantResults[0] != PackageManager.PERMISSION_GRANTED)) {
            permissionsGranted = false;
        }
    }

    @Override
    public void onClick(View v) {
        if(!permissionsGranted) {
            Toast.makeText(this, "Permission to use Location is required.", Toast.LENGTH_LONG).show();
            return;
        }

        Location location = gps.getLocation();
        if (location != null) {
            Toast.makeText(this, String.format("Your Location is \nLatitude: %s\nLongitude: %s", location.getLatitude(), location.getLongitude()), Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(this, "Your Location is currently not available.", Toast.LENGTH_LONG).show();
        }
    }
}
