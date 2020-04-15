package com.niteshsrivats.text.changer;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.niteshsrivats.text.R;

import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private TextView textView;
    private List<Integer> colors = Arrays.asList(Color.RED, Color.BLUE, Color.MAGENTA, Color.CYAN, Color.GREEN, Color.BLACK, Color.YELLOW, Color.GRAY);
    private int size = 16;
    private int colorIndex = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.textView);
    }

    public void changeTextSize(View view) {
        size = (size + 2) % 30;
        if (size < 16) {
            size = 16;
        }
        textView.setTextSize(size);
    }

    public void changeTextColor(View view) {
        colorIndex = (colorIndex + 1) % colors.size();
        textView.setTextColor(colors.get(colorIndex));
    }
}
