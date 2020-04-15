package com.niteshsrivats.shapes;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        DisplayMetrics displayMetrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(displayMetrics);
        int height = displayMetrics.heightPixels;
        int width = displayMetrics.widthPixels;

        ImageView i = findViewById(R.id.imageView);
        Bitmap bg = Bitmap.createBitmap(width, height - 300, Bitmap.Config.ARGB_8888);
        i.setBackgroundDrawable(new BitmapDrawable(this.getResources(), bg));
        Canvas canvas = new Canvas(bg);

        Paint paint = new Paint();
        paint.setAntiAlias(true);

        paint.setColor(Color.parseColor("#403e44"));
        paint.setTextSize(70);

        canvas.drawText("Circle", 220, 200, paint);
        canvas.drawText("Rectangle", 710, 150, paint);
        canvas.drawText("Square", 225, 1100, paint);
        canvas.drawText("Line", 775, 1150, paint);

        paint.setColor(Color.parseColor("#fbc34a"));
        canvas.drawCircle(300, 550, 250, paint);

        paint.setColor(Color.parseColor("#ffe7b1"));
        canvas.drawRect(700, 200, 1025, 900, paint);

        paint.setColor(Color.parseColor("#ff7575"));
        canvas.drawRect(50, 1200, 600, 1750, paint);

        paint.setColor(Color.parseColor("#000000"));
        canvas.drawLine(820, 1200, 820, 1750, paint);
    }
}
