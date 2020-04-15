package com.niteshsrivats.calculator;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private EditText number1, number2;
    private TextView result, symbol;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button addButton = findViewById(R.id.addButton);
        Button subtractButton = findViewById(R.id.subtractButton);
        Button multiplyButton = findViewById(R.id.multiplyButton);
        Button divideButton = findViewById(R.id.divideButton);
        addButton.setOnClickListener(this);
        subtractButton.setOnClickListener(this);
        multiplyButton.setOnClickListener(this);
        divideButton.setOnClickListener(this);

        number1 = findViewById(R.id.number1);
        number2 = findViewById(R.id.number2);

        result = findViewById(R.id.result);
        symbol = findViewById(R.id.symbol);
    }

    @Override
    public void onClick(View view) {
        try {
            float num1 = Integer.parseInt(number1.getText().toString());
            float num2 = Integer.parseInt(number2.getText().toString());
            switch (view.getId()) {
                case R.id.addButton:
                    symbol.setText("+");
                    result.setText(Float.toString(num1 + num2));
                    break;
                case R.id.subtractButton:
                    symbol.setText("-");
                    result.setText(Float.toString(num1 - num2));
                    break;
                case R.id.multiplyButton:
                    symbol.setText("*");
                    result.setText(Float.toString(num1 * num2));
                    break;
                case R.id.divideButton:
                    symbol.setText("/");
                    if (num2 == 0) {
                        result.setText("infinity");
                    } else {
                        result.setText(Float.toString(num1 / num2));
                    }
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + view.getId());
            }
        } catch (NumberFormatException e) {
            result.setText("Invalid Input.");
            e.printStackTrace();
        } catch (IllegalStateException e) {
            result.setText("Unknown Error.");
            e.printStackTrace();
        }
    }
}
