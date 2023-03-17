package com.example.drink;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.biometrics.*;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.util.concurrent.Executor;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    private Button buttonBiometricAuth = null;
    private Executor executor;
    private BiometricPrompt biometricPrompt;
    private BiometricPrompt.PromptInfo promptInfo;
    @Override
    protected void onResume() {
        super.onResume();
        buttonBiometricAuth = (Button) findViewById(R.id.biometricbuttom);

        buttonBiometricAuth.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //TODO inserire logica login con dati biometrici
                promptInfo = new BiometricPrompt.PromptInfo.Builder()
                        .setTitle("Biometric login for my app")
                        .setSubtitle("Log in using your biometric credential")
                        .setAllowedAuthenticators(BIOMETRIC_STRONG | DEVICE_CREDENTIAL)
                        .build();
            }
        });
    }
}