package com.example.finaltalk;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Color;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.example.finaltalk.model.UserModel;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.remoteconfig.FirebaseRemoteConfig;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.UploadTask;

public class SignupActivity extends AppCompatActivity { //회원가입창

    private static final int PICK_FROM_ALBUM = 10;
    private EditText email;
    private EditText name;
    private EditText password;
    private Button signup;
    private String splash_background;
    private ImageView profile;
    private Uri imageUri;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Toast.makeText(SignupActivity.this, "SignupActivity", Toast.LENGTH_SHORT).show();
        Log.i("signupactivity","singupactivity come in");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup);

        FirebaseRemoteConfig mFirebaseRemoteConfig = FirebaseRemoteConfig.getInstance();
        splash_background = mFirebaseRemoteConfig.getString(getString(R.string.rc_color));
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            getWindow().setStatusBarColor(Color.parseColor(splash_background));
        }

        Log.i("signupactivity","singupactivity come in1");


        profile = (ImageView)findViewById(R.id.signupActivity_imageview_profile);
        profile.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                Intent intent = new Intent(Intent.ACTION_PICK);
                intent.setType(MediaStore.Images.Media.CONTENT_TYPE);
                startActivityForResult(intent, PICK_FROM_ALBUM);
            }
        });
        Log.i("signupactivity","singupactivity come in2");
        email = (EditText) findViewById(R.id.signupActivity_edittext_email);
        name = (EditText) findViewById(R.id.signupActivity_edittext_name);
        password = (EditText) findViewById(R.id.signupActivity_edittext_password);
        signup = (Button) findViewById(R.id.signupActivity_button_signup);
        signup.setBackgroundColor(Color.parseColor(splash_background));

        signup.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.i("signupactivity","singupactivity come in3");

                if(imageUri == null){
                    imageUri = Uri.parse("android.resource://"+getPackageName()+"/"+ R.drawable.image);
                }

                if(email.getText().toString() == null || name.getText().toString() == null || password.getText().toString() == null || imageUri == null){
                    Toast.makeText(SignupActivity.this, "입력하지 않은 칸이 있습니다.", Toast.LENGTH_LONG).show();
                    return;
                }



                Log.i("signupactivity","singupactivity come in4");

                FirebaseAuth.getInstance()
                .createUserWithEmailAndPassword(email.getText().toString(),password.getText().toString())
                .addOnCompleteListener(SignupActivity.this, new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        Log.i("signupactivity","singupactivity come in5");
                        final String uid = task.getResult().getUser().getUid();  //uid값 받아와서 저장
                        Log.i("signupactivity","singupactivity come in6");

                        FirebaseStorage.getInstance().getReference().child("userImages").child(uid).putFile(imageUri).addOnCompleteListener(new OnCompleteListener<UploadTask.TaskSnapshot>() {
                            @Override
                            public void onComplete(@NonNull Task<UploadTask.TaskSnapshot> task) {
                                Log.i("signupactivity","6666666666666666666666");
                                String imageUrl = task.getResult().getStorage().getDownloadUrl().toString();  //현재 downloadURL을 사용할수없다?? -> 이미자가 안불러짐
                                Log.i("signupactivity","777777777777777777777777");
                                Log.d("signupactivity",imageUrl);
                                UserModel userModel = new UserModel();
                                userModel.userName = name.getText().toString();
                                userModel.profileImageUrl = imageUrl;
                                userModel.uid = FirebaseAuth.getInstance().getCurrentUser().getUid();

                                FirebaseDatabase.getInstance().getReference().child("users").child(uid).setValue(userModel).addOnSuccessListener(new OnSuccessListener<Void>() {
                                    @Override
                                    public void onSuccess(Void aVoid) {
                                        SignupActivity.this.finish(); //회원가입 했을때 회원가입창 닫음
                                    }
                                });
                            }
                        });
                    }
                });
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if(requestCode == PICK_FROM_ALBUM && resultCode == RESULT_OK){
            profile.setImageURI(data.getData()); //회원가입창 가운데 뷰를 바꿈
            imageUri = data.getData();//이미지 경로 원본
        }
    }
}
