package com.niteshsrivats.sql.database;

import android.location.Address;
import android.location.Geocoder;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;
import java.util.List;
import java.util.Locale;

public class MainActivity extends AppCompatActivity implements OnClickListener {

    EditText addressText;
    TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
        addressText = findViewById(R.id.editText);
        findViewById(R.id.button).setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        String address = addressText.getText().toString();
        Geocoder geocoder = new Geocoder(this, Locale.getDefault());
        try {
            List<Address> addresses = geocoder.getFromLocationName(address, 1);
            double latitude = addresses.get(0).getLatitude();
            double longitude = addresses.get(0).getLongitude();
            textView.setText(String.format("Latitude: %s\nLongitude: %s", latitude, longitude));
        } catch (IOException e) {
            textView.setText("No results found");
        }
    }
}
