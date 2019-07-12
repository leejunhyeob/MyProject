package com.example.finaltalk;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Toast;

import com.example.finaltalk.fragment.PeopleFragment;

public class SubMainActivity extends AppCompatActivity { //로그인후 유저목록창

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Toast.makeText(SubMainActivity.this, "SubMainActivity", Toast.LENGTH_SHORT).show();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub_main);

        getFragmentManager().beginTransaction().replace(R.id.submainactivity_framelayout,new PeopleFragment()).commit();
    }
}
