#include "main.h"
#include "timer.h"
#include "ball.h"
#include "bricks.h"
#include "ground.h"
#include "coins.h"
#include "enemya.h"
#include "enemyb.h"
#include "enemyc.h"
#include "powerup.h"
#include "powerupb.h"
#include "balloon.h"
#include "score.h"
#include "magnet.h"
#include "ring.h"
#include "powerupc.h"
#include "powerupd.h"
#include "dragon.h"


using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;

Bricks brik;

Enemya ena;

Enemyb enb[20];

Enemyc enc;

Coins coin_array[500];
Coins coin_array2[500];

Powerup pup;

Powerupb pupb;

Powerupc pupc;

Powerupd pupd;

Balloon bon[10];

Ring rin;


Magnet mang1;
Magnet mang2;
Magnet mang3;
Magnet mang4;
Magnet mang5;
Magnet mang6;
Magnet mang7;
Magnet mang8;
Magnet mang9;
Magnet mang10;


Score ses;
Score sec;
Score seo;
Score ser;
Score see;
Score seon;
Score sete;
Score sehu;
Score seth;
Score selt;
Score seli;

Dragon viserion;


double dist = 0;
int flg = -1, boomf = 0, life = 3, dlife = 3,mangf=0, mangr=0, cmotion = 0, pupcf = 0, pupdf = 0, ranf2 = 0, ranf3 = 0;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0, enaf=0;
float camera_rotation_angle = 0;
double xpos, ypos, mangs = 0;
double time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0, time7 = 0, time8 = 0, time9 = 0, time10 = 0, time11 = 0, time12 = 0, time13 = 0, time14 = 0, time15 = 0, time16 = 0, time17 = 0;
int projectile_time = 60, game_time = 6000,num_coin=500, leftauto = 0, shield = 0, ranf=0, num_bon = 10, bon_ind = 0, scored = 0, tempdis = 0;
Ground toppo;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {

    if(cmotion)
    {
        //cout<<ball1.position.x<<"\n";
        //cout<<ball1.position.y<<"\n";
    }
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    //glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye (0, 0, 1);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;
      // MVP = Projection * View * Model
    toppo.draw(VP);
    brik.draw(VP);
    rin.draw(VP);
    if(shield != -1)
        pupb.draw(VP);
    if(dist > 1070)
        ranf = 1;
    if(!leftauto && ranf)
    {
        pup.draw(VP);
    }
    if(dist > 90)
        ranf2 = 1;
    if(!pupcf && ranf2)
    {
        pupc.draw(VP);
    }
    if(dist > 500)
        ranf3 = 1;
    if(ranf3 && !pupdf)
    {
        pupd.draw(VP);
    }
    for (int i = 0; i < num_coin; i++) {
        if(coin_array[i].alive)
            coin_array[i].draw(VP);
    }
    for (int i = 0; i < num_coin; i++) {
        if(coin_array2[i].alive && pupcf)
            coin_array2[i].draw(VP);
    }

    for(int i = 0; i<10; i++)
    {
        enb[i].draw(VP);
    }
    
    time1 = glfwGetTime();


    if(dist>140 && dist<142 && flg<0 && !leftauto)
    {
        flg = 0;
        time2 = glfwGetTime();
        enaf = 1;
    }
    if(time1-time2>2 && flg==0)
    {
        flg = 1;
        time3 = glfwGetTime();
    }
    else if(time1-time3>10 && flg==1)
    {
        flg = 2;
        time4 = glfwGetTime();
    }
    else if(time1-time4>2 && flg==2)
    {
        flg = 3;
        time5 = glfwGetTime();
    }
    else if(time1-time5>10 && flg==3)
    {
        flg = 4;
        time6 = glfwGetTime();
    }
    else if(time1-time6>2 && flg==4)
    {
        flg = 5;
        time7 = glfwGetTime();
    }
    else if(time1-time7>10 && flg==5)
    {
        flg = -1;
        enaf = 0;
    }

    if(dist>1140 && dist<1142 && flg<0 && !leftauto)
    {
        flg = 0;
        time2 = glfwGetTime();
        enaf = 1;
    }
    if(time1-time2>2 && flg==0)
    {
        flg = 1;
        time3 = glfwGetTime();
    }
    else if(time1-time3>10 && flg==1)
    {
        flg = 2;
        time4 = glfwGetTime();
    }
    else if(time1-time4>2 && flg==2)
    {
        flg = 3;
        time5 = glfwGetTime();
    }
    else if(time1-time5>10 && flg==3)
    {
        flg = 4;
        time6 = glfwGetTime();
    }
    else if(time1-time6>2 && flg==4)
    {
        flg = 5;
        time7 = glfwGetTime();
    }
    else if(time1-time7>10 && flg==5)
    {
        flg = -1;
        enaf = 0;
    }
    if(enaf)
    {
        //printf("in4\n");
        ena.draw(VP,flg);
    }
    enc.draw(VP);
    if(bon[bon_ind].alive)
        bon[bon_ind].draw(VP);
    // Scene render
    if(mangf)
    {
        mang1.draw(VP,0);
        mang2.draw(VP,0);
        mang3.draw(VP,0);
        mang4.draw(VP,0);
        mang5.draw(VP,0);
    }
    if(mangr)
    {
        mang6.draw(VP,1);
        mang7.draw(VP,1);
        mang8.draw(VP,1);
        mang9.draw(VP,1);
        mang10.draw(VP,1);
    }

    viserion.draw(VP,0);

    ball1.draw(VP);

    ses.draw(VP,-1);
    sec.draw(VP,-2);
    seo.draw(VP,-3);
    ser.draw(VP,-4);
    see.draw(VP,-5);
    seon.draw(VP,(scored/10)%10);
    sete.draw(VP,(scored/100)%10);
    sehu.draw(VP,(scored/1000)%10);
    seth.draw(VP,(scored/10000)%10);
    selt.draw(VP,10);
    seli.draw(VP,life);
}

void tick_input(GLFWwindow *window) {
    if (leftauto) {
        if (ball1.position.x <= 0) {
            ball1.position.x += 0.15;
        }
        else{
            brik.position.x -= 0.15;
            viserion.position.x -= 0.15;
            rin.position.x -= 0.15;
            pup.position.x -= 0.15;
            for(int i=0; i < 10; i++)
                enb[i].position.x -= 0.15;        
            for(int i=0; i < num_coin; i++)
                coin_array[i].position.x -= 0.15;
            for(int i=0; i < num_coin; i++)
                coin_array2[i].position.x -= 0.15;
        }
        for(int i=0; i < num_coin; i++)
        {
            if(coin_array[i].position.x < ball1.position.x + 0.1 && coin_array[i].position.x > ball1.position.x - 0.1)
            {
                coin_array[i].alive = 0;
                scored += 20;
            }
            if(coin_array2[i].position.x < ball1.position.x + 0.1 && coin_array2[i].position.x > ball1.position.x - 0.1)
            {
                coin_array2[i].alive = 0;
                scored += 20;
            }
        }
        dist = dist + 10*0.15;
        bon[bon_ind].position.x = ball1.position.x;
        bon[bon_ind].position.y = (ball1.position.y - 0.55);
        time9 = glfwGetTime();
        if(time9-time8>3)
            leftauto = 0;

    }
    else
    {
        int left  = glfwGetKey(window, GLFW_KEY_LEFT);
        int right = glfwGetKey(window, GLFW_KEY_RIGHT);
        int up    = glfwGetKey(window, GLFW_KEY_SPACE);
        int jp    = glfwGetKey(window, GLFW_KEY_UP);
        int key_b = glfwGetKey(window, GLFW_KEY_B);
        int mouse_clicked = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        glfwSetScrollCallback(window, scroll_callback);
        
        glfwGetCursorPos(window, &xpos, &ypos);
        //cout<<mouse_scroll<<"\n";
        xpos = (xpos - 450)/112.5;
        ypos = (ypos - 450)/112.5;
        if (left && dist > 0.5) {
            if (ball1.position.x + 2.9 >= 0) {
                ball1.position.x -= ball1.xspeed;    
                //ball1.dir = false;
            }
            else{
                brik.position.x += ball1.xspeed;
                viserion.position.x += ball1.xspeed;
                rin.position.x += ball1.xspeed;

                for(int i=0; i < 10; i++)
                    enb[i].position.x += ball1.xspeed;
                for(int i=0; i < num_coin; i++)
                    coin_array[i].position.x += ball1.xspeed;
                for(int i=0; i < num_coin; i++)
                    coin_array2[i].position.x += ball1.xspeed;
                if(ranf)
                    pup.position.x += ball1.xspeed;
                if(ranf2)
                    pupc.position.x += ball1.xspeed;
                if(ranf3)
                    pupd.position.x += ball1.xspeed;
                if(!shield)
                    pupb.position.x += ball1.xspeed;
                if(bon[bon_ind].thro)
                    bon[bon_ind].position.x -= ball1.xspeed;
            }
            dist = dist - 10*ball1.xspeed;
        }
        if (right  && dist < 1900) {
            if (ball1.position.x <= 0) {
                ball1.position.x += ball1.xspeed;
            }
            else{
                brik.position.x -= ball1.xspeed;
                viserion.position.x -= ball1.xspeed;
                rin.position.x -= ball1.xspeed;
                if(ranf)
                    pup.position.x -= ball1.xspeed;
                if(ranf2)
                    pupc.position.x -= ball1.xspeed;
                if(ranf3)
                    pupd.position.x -= ball1.xspeed;
                if(!shield)
                    pupb.position.x -= ball1.xspeed;
                if(bon[bon_ind].thro)
                    bon[bon_ind].position.x -= ball1.xspeed;
                for(int i=0; i < 10; i++)
                    enb[i].position.x -= ball1.xspeed;        
                for(int i=0; i < num_coin; i++)
                    coin_array[i].position.x -= ball1.xspeed;
                for(int i=0; i < num_coin; i++)
                    coin_array2[i].position.x -= ball1.xspeed;
            }
            dist = dist + 10*ball1.xspeed;
            //printf("%f\n", dist);

        }
        
        if (right  && dist < 2000 && dist > 1900)
        {
            if (ball1.position.x - 3.7 <= 0)
                ball1.position.x += ball1.xspeed;
            dist = dist + 10*ball1.xspeed;
            //printf("%f\n", dist);
        }

        if (up && ball1.position.y<3.1 && !mangf) {
            //cout<<"Here"<<endl;
            ball1.yspeed = 0.06;
            ball1.position.y += 0.06;

            ball1.jump = 1;
        }
        if (up && ball1.position.y>=3.1 && !left) {
            //cout<<"Here"<<endl;
            if (ball1.position.x - 1 <= 0) {
                //ball1.dir = true;
                ball1.position.x += (ball1.xspeed-0.01);
            }
            else{
                brik.position.x -= (ball1.xspeed-0.01);
                viserion.position.x -= (ball1.xspeed-0.01);
                rin.position.x -= (ball1.xspeed-0.01);
                if(ranf)
                    pup.position.x -= (ball1.xspeed-0.01);
                if(ranf2)
                    pupc.position.x -= (ball1.xspeed-0.01);
                if(ranf3)
                    pupd.position.x -= (ball1.xspeed-0.01);
                if(!shield)
                    pupb.position.x -= (ball1.xspeed-0.01);
                if(bon[bon_ind].thro)
                    bon[bon_ind].position.x -= (ball1.xspeed-0.01);
                for(int i=0; i < 10; i++)
                    enb[i].position.x -= (ball1.xspeed-0.01);        
                for(int i=0; i < num_coin; i++)
                    coin_array[i].position.x -= (ball1.xspeed-0.01);
                for(int i=0; i < num_coin; i++)
                    coin_array2[i].position.x -= (ball1.xspeed-0.01);
            }
            dist = dist + 10*(ball1.xspeed-0.01);
        }
        if (jp && !ball1.jump && !mangf) {
            //cout<<"Here"<<endl;
            ball1.yspeed = 0.15;
            ball1.jump = 1;
        }
        if(key_b)
        {
            bon[bon_ind].thro = 1;
        }
        if (mouse_clicked) {
            screen_zoom = 1;
            reset_screen();
            //printf("inmo\n");
        }
    }
}

void tick_elements() {
    viserion.tick();
    if(viserion.position.y<=0 && !viserion.fire)
    {
        viserion.fire = 1;
        time16 = glfwGetTime();
    }
    time17 = glfwGetTime();
    if(time17-time16>0.3 && viserion.fire)
    {
        viserion.fire = 0;
    }
    if(dist-tempdis>0)
        scored += (dist-tempdis);
    tempdis = dist;
    if(!leftauto){
        if(mangf)
        {   
            if(ball1.position.y<2.6)
            {
                ball1.yspeed += 0.0001;
                ball1.position.y += ball1.yspeed;
            }
        }
        if((dist > 980 && dist < 984) || (dist>1400 && dist<1402) )
        {
            mangf = 1;
            time12 = glfwGetTime();
        }
        time13 = glfwGetTime();
        if(time13 - time12 > 8 && mangf)
        {
            mangf = 0;
            ball1.yspeed = 0;
            ball1.jump = 1;
        }
        if((dist > 10 && dist < 12) || (dist>1500 && dist<1502) )
        {
            mangr = 1;
            time14 = glfwGetTime();
        }
        time15 = glfwGetTime();
        if(mangr)
        {
            if (ball1.position.x <= 0) {
                ball1.position.x += mangs;
            }
            else{
                brik.position.x -= mangs;
                viserion.position.x -= mangs;
                rin.position.x -= mangs;
                if(ranf)
                    pup.position.x -= mangs;
                if(ranf2)
                    pupc.position.x -= mangs;
                if(ranf3)
                    pupd.position.x -= mangs;
                if(!shield)
                    pupb.position.x -= mangs;
                if(bon[bon_ind].thro)
                    bon[bon_ind].position.x -= mangs;
                for(int i=0; i < 10; i++)
                    enb[i].position.x -= mangs;        
                for(int i=0; i < num_coin; i++)
                    coin_array[i].position.x -= mangs;
                for(int i=0; i < num_coin; i++)
                    coin_array2[i].position.x -= mangs;
            }
            dist = dist + 10*mangs;
            mangs += 0.0001;
        }
        if(time15 - time14 > 5 && mangr)
        {
            mangr = 0;
            ball1.xspeed = 0.03;
            mangs = 0;
        }

        ball1.tick();
        ena.tick();
        time11 = glfwGetTime();
        if(time11 - time10 > 20 && shield == 1)
            shield = -1;
        if(shield == 0)
            pupb.tick();
        if(ranf)
        {
            pup.tick();
        }
        if(ranf2)
        {
            pupc.tick();
        }
        if(ranf3)
        {
            pupd.tick();
        }
        for(int i=0;i<num_coin;i++)
            coin_array[i].tick();
        for(int i=0;i<num_coin;i++)
            coin_array2[i].tick();
        if(dist>40 && dist<42)
            boomf = 1;
        if(dist>900 && dist<902)
            boomf = 1;
        if(enc.position.x>5.1)
        {
            boomf = 0;
            enc.position.x = 5;
            enc.xspeed = 0.18;
            enc.position.y = 2.5;
        }
        if(boomf)
            enc.tick();

        if (ball1.jump) {
            if(ball1.position.y<3.1){

                ball1.yspeed -= 0.005;
                ball1.position.y += ball1.yspeed;
            }
            else{

                ball1.yspeed = 0;
                ball1.yspeed -= 0.005;
                ball1.position.y += ball1.yspeed;
            }
        }
        if (ball1.position.y <= -1.1) {

            ball1.position.y = -1.1;
            ball1.jump = 0;
            ball1.yspeed = 0;
        }
        if(bon[bon_ind].thro)
        {
            bon[bon_ind].position.x += bon[bon_ind].xspeed;
            bon[bon_ind].yspeed -= 0.005;
            bon[bon_ind].position.y += bon[bon_ind].yspeed;
        }
        if(bon[bon_ind].thro == 0 && bon[bon_ind].alive)
        {
            bon[bon_ind].position.x = ball1.position.x;
            bon[bon_ind].position.y = (ball1.position.y - 0.55);
        }
        if (bon[bon_ind].position.y <= -1.9 || bon[bon_ind].position.y >= 3) {

            bon[bon_ind].position.y = -1.9;
            bon[bon_ind].thro = 0;
            bon[bon_ind].alive = 0;
            if(bon_ind<9)
                bon_ind++;
        }
        for (int i = 0; i < num_coin; i++) {
            
            if (collision_coin_detect(i,1) && coin_array[i].alive) {
                scored += 20;
                coin_array[i].alive = 0;
            }
        }
        for (int i = 0; i < num_coin; i++) {
            
            if (collision_coin_detect(i,2) && coin_array2[i].alive && pupcf) {
                scored += 20;
                coin_array2[i].alive = 0;
            }
        }
        if(shield == 1)
        {
            pupb.position.x = ball1.position.x-0.16;
            pupb.position.y = ball1.position.y-0.5;
        }
        if(shield == 0 || shield == -1)
        {
            if(collision_enemya())
            {
                if(scored>30)
                    scored -= 30;
                else
                    scored = 0;
                // cout<<flg<<" = flag\n";
                // cout<<"dead\n";
            }
            for(int j=0; j<20; j++){

                if(collision_enemyb(j) && enb[j].working)
                {
                    if(life>0)
                        life -= 1;
                    if(life==0)
                        quit(window);
                    ball1.position.y = 0;
                    ball1.position.x = -3.3;
                    ball1.jump = 1;
                }
            }
            if(collision_enemyc() && boomf)
            {
                //cout<<"dead\n";
                ball1.position.x += 0.07;
                if(scored>18)
                    scored -= 18;
                else
                    scored = 0;
            }
        }
        if(collision_pupa() && ranf)
        {
             leftauto = 1;
             scored += 200;
             time8 = glfwGetTime();

        }
        if(collision_pupb() && shield == 0)
        {
             shield = 1;
             time10 = glfwGetTime();

        }
        if(collision_pupc() && ranf2 && !pupcf)
        {
             pupcf = 1;
             scored += 200;

        }
        if(collision_pupd() && ranf3 && !pupdf)
        {
             life+=2;
             pupdf = 1;
             scored += 200;

        }
        for(int j=0; j<20; j++){

            if(collision_enemyb_balloon(j) && enb[j].working && bon[bon_ind].thro)
            {
                enb[j].working = 0;
                bon[bon_ind].thro = 0;
                bon[bon_ind].alive = 0;
                scored += 20;
                if(bon_ind<9)
                    bon_ind++;
                //cout<<"extinguihed\n";
            }
        }
        if(collision_circle())
        {
             //cout<<"colcircle\n";
             cmotion = 1;
             circular_motion();

        }
        if(collision_dragon())
        {
            if(life>0)
                life -= 1;
            if(life==0)
            {
                cout<<"BETTER LUCK NEXT TIME\n";
                cout<<"YOUR SCORE = "<<scored/10<<"\n";
                cout<<"LIVES REMAINING = "<<life<<"\n";
                cout<<"TOTAL SCORE = "<<1 *(scored/10)<<"\n";
                quit(window);
            }
            ball1.position.y = 0;
            ball1.position.x = -3.3;
            ball1.jump = 1;
        }
        if(collision_dragon_balloon() && bon[bon_ind].thro)
        {
            //cout<<"collide\n";
            dlife -= 1;
            bon[bon_ind].thro = 0;
            bon[bon_ind].alive = 0;
            scored += 200;
            if(bon_ind<9)
                bon_ind++;
            if(dlife<=0)
            {
                cout<<"YOU WON\n";
                cout<<"YOUR SCORE = "<<scored/10<<"\n";
                cout<<"LIVES REMAINING = "<<life<<"\n";
                cout<<"TOTAL SCORE = "<<life *(scored/10)<<"\n";
                quit(window);
            }
        }

    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    ses = Score(-3.8,3.97);
    sec = Score(-3.5,3.97);
    seo = Score(-3.2,3.97);
    ser = Score(-2.9,3.97);
    see = Score(-2.6,3.97);
    seth = Score(-2.1,3.97);
    sehu = Score(-1.8,3.97);
    sete = Score(-1.5,3.97);
    seon  = Score(-1.2,3.97);
    selt  = Score(3.1,3.97);
    seli  = Score(3.55,3.97);

    rin = Ring(172,0);

    for (int i = 0; i < num_coin; i++) {
        
        double xi = ((double) rand()*(190)/(double)RAND_MAX) - 3;
        double yi = ((double) rand()*(2)/(double)RAND_MAX) - 0.7;
        coin_array[i] = Coins(xi, yi, 0.1, COLOR_YELLOW);
        coin_array[i].alive = 1;
        xi = xi + 1;
    }
    for (int i = 0; i < num_coin; i++) {
        
        double xi = ((double) rand()*(190)/(double)RAND_MAX) - 3;
        double yi = ((double) rand()*(2)/(double)RAND_MAX) - 0.7;
        coin_array2[i] = Coins(xi, yi, 0.1, COLOR_GREEN);
        coin_array2[i].alive = 1;
        xi = xi + 1;
    }
    mang1 = Magnet(0, 3.13);
    mang2 = Magnet(-1, 3.13);
    mang3 = Magnet(-2, 3.13);
    mang4 = Magnet(1, 3.13);
    mang5 = Magnet(2, 3.13);
    mang6 = Magnet(3.97, 0.5);
    mang7 = Magnet(3.97, 1.5);
    mang8 = Magnet(3.97, 2.5);
    mang9 = Magnet(3.97, -0.5);
    mang10 = Magnet(3.97, -1.5);
    brik = Bricks(-2, -1, COLOR_WHITE);
    for(int j=0; j < num_bon; j++)
        bon[j] = Balloon(-5, 5, 0.15);

    ball1 = Ball(-3, -1.10, COLOR_RED);

    viserion = Dragon(190,0);
    ena = Enemya(0, 0, COLOR_RED);
    enc = Enemyc(5,2.5,COLOR_BROWN);
    toppo = Ground(0,-2, COLOR_BLUE, COLOR_GREY, COLOR_DBLUE, COLOR_WHITE);
    pup = Powerup(-2,2);
    pupb = Powerupb(-2,2);
    pupc = Powerupc(-2,2);
    pupd = Powerupd(-2,2);

    enb[0] = Enemyb(2, 2, 0.2, 0, COLOR_GREY);
    enb[1] = Enemyb(8, 2, 0.2, -1, COLOR_GREY);
    enb[2] = Enemyb(152, 2.2, 0.2, -1, COLOR_GREY);
    enb[3] = Enemyb(157, 1.8, 0.2, 1, COLOR_GREY);
    enb[4] = Enemyb(172, 2.1, 0.2, 0.3, COLOR_GREY);
    enb[5] = Enemyb(177, 1.7, 0.2, 1, COLOR_GREY);
    enb[6] = Enemyb(86, 2, 0.2, -0.7, COLOR_GREY);
    enb[7] = Enemyb(90, 1.8, 0.2, 0.7, COLOR_GREY);
    enb[8] = Enemyb(99, 2, 0.2, 1.1, COLOR_GREY);
    enb[9] = Enemyb(110, 2, 0.2, -1.1, COLOR_GREY);
    enb[10] = Enemyb(114, 2, 0.2, 0, COLOR_GREY);
    enb[11] = Enemyb(123, 2, 0.2, -1, COLOR_GREY);
    enb[12] = Enemyb(60, 2.2, 0.2, -1, COLOR_GREY);
    enb[13] = Enemyb(45, 1.8, 0.2, 1, COLOR_GREY);
    enb[14] = Enemyb(132, 2.1, 0.2, 0.3, COLOR_GREY);
    enb[15] = Enemyb(138, 1.7, 0.2, 1, COLOR_GREY);
    enb[16] = Enemyb(182, 2, 0.2, -0.7, COLOR_GREY);
    enb[17] = Enemyb(142, 1.8, 0.2, 0.7, COLOR_GREY);
    enb[18] = Enemyb(144, 2, 0.2, 1.1, COLOR_GREY);
    enb[19] = Enemyb(165, 2, 0.2, -1.1, COLOR_GREY);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    // cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    // cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    // cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    // cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    system("aplay ../UF.wav&");
    srand(time(0));

    int width  = 700;
    int height = 700;

    window = initGLFW(width, height);

    initGL (window, width, height);
    

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }
    cout<<"YOUR SCORE = "<<scored/10<<"\n";
    cout<<"LIVES REMAINING = "<<life<<"\n";
    cout<<"TOTAL SCORE = "<<life *(scored/10)<<"\n";
    quit(window);
    // audio_close();

}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

int collision_coin_detect(int idx,int wo) {

    if(wo == 1)
    {
        float xdis = (ball1.position.x - coin_array[idx].position.x - 0.2) * (ball1.position.x - coin_array[idx].position.x - 0.2);
        float ydis = (ball1.position.y - 0.45 - coin_array[idx].position.y) * (ball1.position.y - 0.45 - coin_array[idx].position.y);
        float dis = sqrt(xdis + ydis);
        if (dis <= 0.5) {
            return 1;
        }
    }
    if(wo == 2)
    {
        float xdis = (ball1.position.x - coin_array2[idx].position.x - 0.2) * (ball1.position.x - coin_array2[idx].position.x - 0.2);
        float ydis = (ball1.position.y - 0.45 - coin_array2[idx].position.y) * (ball1.position.y - 0.45 - coin_array2[idx].position.y);
        float dis = sqrt(xdis + ydis);
        if (dis <= 0.5) {
            return 1;
        }
    }
    return 0;
}

int collision_enemya(){
    if(flg == 1)
    {
        double updis = ena.position.y - 0.75 - ball1.position.y;
        double downdis = ball1.position.y - 0.95 - ena.position.y;
        if(updis<=0 && ena.position.y>ball1.position.y)
            return 1;
        if(downdis<=0 && ena.position.y<ball1.position.y)
            return 1;
    }
    else if(flg == 3)
    {
        double updis = ena.position.y + 0.35 - ball1.position.y;
        double downdis = ball1.position.y - 2.15 - ena.position.y;
        if(updis<=0 && (ena.position.y + 1.2)>ball1.position.y)
            return 1;
        if(downdis<=0 && (ena.position.y + 1.2)<ball1.position.y)
            return 1;
    }
    else if(flg == 5)
    {
        double updis = ena.position.y + 1.55 - ball1.position.y;
        double downdis = ball1.position.y - 3.35 - ena.position.y;
        if(updis<=0 && (ena.position.y + 2.4)>ball1.position.y)
            return 1;
        if(downdis<=0 && (ena.position.y + 2.4)<ball1.position.y)
            return 1;
    }
    return 0;
}

int collision_enemyb(int id){
    float xdis = (ball1.position.x - enb[id].position.x - 0.2) * (ball1.position.x - enb[id].position.x - 0.2);
    float ydis = (ball1.position.y + 0.18 - enb[id].position.y) * (ball1.position.y + 0.18 - enb[id].position.y);
    float dis = sqrt(xdis + ydis);
    if (dis <= 0.5) {
        return 1;
    }
    float xdis2 = (ball1.position.x - (enb[id].position.x + enb[id].xshift) - 0.2) * (ball1.position.x - (enb[id].position.x + enb[id].xshift) - 0.2);
    float ydis2 = (ball1.position.y + 0.18 - (enb[id].position.y+1)) * (ball1.position.y +  0.18- (enb[id].position.y+1));
    float dis2 = sqrt(xdis2 + ydis2);
    if (dis2 <= 0.5) {
        return 1;
    }
    if(ball1.position.y > enb[id].position.y && ball1.position.y < ( enb[id].position.y + 1 ))
    {
        float perd = sqrt(1 + enb[id].xshift*enb[id].xshift);
        float subli1 = ball1.position.x - 0.15 - enb[id].xshift*ball1.position.y + enb[id].position.y*enb[id].xshift - enb[id].position.x - 0.15;
        float subli2 = ball1.position.x - 0.15 - enb[id].xshift*ball1.position.y + enb[id].position.y*enb[id].xshift - enb[id].position.x + 0.15;
        if(subli1 < 0)
            subli1 = 0 - subli1;
        if(subli2 < 0)
            subli2 = 0 - subli2;
        float dis3 = subli1/perd;
        float dis4 = subli2/perd;
        if( dis3 < 0.3 || dis4 < 0.3 )
        {
            return 1;
        }
    }

    return 0;
}

int collision_enemyc(){
    float xdis = (ball1.position.x - enc.position.x - 0.2) * (ball1.position.x - enc.position.x - 0.2);
    float ydis = (ball1.position.y - enc.position.y - 0.4) * (ball1.position.y - enc.position.y -0.4);
    float dis = sqrt(xdis + ydis);
    if (dis <= 0.6) {
        return 1;
    }
    return 0;
}

int collision_pupa(){
    float xdis = (ball1.position.x - pup.position.x - 0.16) * (ball1.position.x - pup.position.x - 0.16);
    float ydis = (ball1.position.y - pup.position.y - 0.3) * (ball1.position.y - pup.position.y - 0.3);
    float dis = sqrt(xdis + ydis);
    //cout<<dis<<"\n";
    if (dis <= 0.5) {
        return 1;
    }

    return 0;
}

int collision_pupb(){
    float xdis = (ball1.position.x - pupb.position.x - 0.16) * (ball1.position.x - pupb.position.x - 0.16);
    float ydis = (ball1.position.y - pupb.position.y - 0.3) * (ball1.position.y - pupb.position.y - 0.3);
    float dis = sqrt(xdis + ydis);
    //cout<<dis<<"\n";
    if (dis <= 0.5) {
        return 1;
    }

    return 0;
}

int collision_pupc(){
    float xdis = (ball1.position.x - pupc.position.x - 0.16) * (ball1.position.x - pupc.position.x - 0.16);
    float ydis = (ball1.position.y - pupc.position.y - 0.3) * (ball1.position.y - pupc.position.y - 0.3);
    float dis = sqrt(xdis + ydis);
    //cout<<dis<<"\n";
    if (dis <= 0.5) {
        return 1;
    }

    return 0;
}

int collision_pupd(){
    float xdis = (ball1.position.x - pupd.position.x - 0.16) * (ball1.position.x - pupd.position.x - 0.16);
    float ydis = (ball1.position.y - pupd.position.y - 0.3) * (ball1.position.y - pupd.position.y - 0.3);
    float dis = sqrt(xdis + ydis);
    //cout<<dis<<"\n";
    if (dis <= 0.5) {
        return 1;
    }

    return 0;
}

int collision_enemyb_balloon(int id){
    float xdis = (bon[bon_ind].position.x - enb[id].position.x) * (bon[bon_ind].position.x - enb[id].position.x);
    float ydis = (bon[bon_ind].position.y - enb[id].position.y) * (bon[bon_ind].position.y - enb[id].position.y);
    float dis = sqrt(xdis + ydis);
    if (dis <= 0.5) {
        return 1;
    }
    float xdis2 = (bon[bon_ind].position.x - (enb[id].position.x + enb[id].xshift)) * (bon[bon_ind].position.x - (enb[id].position.x + enb[id].xshift));
    float ydis2 = (bon[bon_ind].position.y - (enb[id].position.y+1)) * (bon[bon_ind].position.y - (enb[id].position.y+1));
    float dis2 = sqrt(xdis2 + ydis2);
    if (dis2 <= 0.45) {
        return 1;
    }
    if(bon[bon_ind].position.y > enb[id].position.y && bon[bon_ind].position.y < ( enb[id].position.y + 1 ))
    {
        float perd = sqrt(1 + enb[id].xshift*enb[id].xshift);
        float subli1 = bon[bon_ind].position.x - enb[id].xshift*bon[bon_ind].position.y + enb[id].position.y*enb[id].xshift - enb[id].position.x - 0.15;
        float subli2 = bon[bon_ind].position.x - enb[id].xshift*bon[bon_ind].position.y + enb[id].position.y*enb[id].xshift - enb[id].position.x + 0.15;
        if(subli1 < 0)
            subli1 = 0 - subli1;
        if(subli2 < 0)
            subli2 = 0 - subli2;
        float dis3 = subli1/perd;
        float dis4 = subli2/perd;
        if( dis3 < 0.15 || dis4 < 0.15 )
        {
            return 1;
        }
    }

    return 0;
}


int collision_circle(){
    float xdis = (ball1.position.x - rin.position.x + 2 - 0.16) * (ball1.position.x - rin.position.x + 2 - 0.16);
    float ydis = (ball1.position.y - rin.position.y - 0.5) * (ball1.position.y - rin.position.y - 0.5);
    float dis = sqrt(xdis + ydis);
    //cout<<dis<<"\n";
    if (dis <= 0.4) {
        return 1;
    }

    return 0;
}

int collision_dragon()
{
    if(viserion.fire)
    {
        double pedis = (ball1.position.y - 0.45) - 0.08 - 0.571*((ball1.position.x - 0.16) - viserion.position.x + 0.27);
        pedis = pedis/1.326;
        if(pedis<0)
            pedis = 0 - pedis;
        if(pedis<0.4)
            return 1;
        double pedis2 = (ball1.position.y - 0.45) - 0.08 - 1.772*((ball1.position.x - 0.16) - viserion.position.x + 0.27);
        pedis2 = pedis2/4.134;
        if(pedis2<0)
            pedis2 = 0 - pedis2;
        //cout<<pedis2<<"\n";
        if(pedis2<0.13)
            return 1;
    }
    float xdis = (ball1.position.x - 0.16 - viserion.position.x - 0.5) * (ball1.position.x - 0.16 - viserion.position.x - 0.5);
    float ydis = (ball1.position.y - 0.45 - viserion.position.y - 0.3) * (ball1.position.y - 0.45 - viserion.position.y - 0.3);
    float dis = sqrt(xdis + ydis);
    //cout<<dis<<"\n";
    if (dis <= 0.9) {
        return 1;
    }
    return 0;
}

int collision_dragon_balloon()
{
    float xdis = (bon[bon_ind].position.x - 0.16 - viserion.position.x - 0.5) * (bon[bon_ind].position.x - 0.16 - viserion.position.x - 0.5);
    float ydis = (bon[bon_ind].position.y - 0.45 - viserion.position.y - 0.3) * (bon[bon_ind].position.y - 0.45 - viserion.position.y - 0.3);
    float dis = sqrt(xdis + ydis);
    //cout<<dis<<"\n";
    if (dis <= 0.7) {
        return 1;
    }
    return 0;
}

void circular_motion()
{
    ball1.jump = 0;
    ball1.position.x = rin.position.x - 2 + 0.35;
    ball1.position.y = rin.position.y + 1;
    double spee = ball1.yspeed/100, addy = 0;
    while(ball1.position.x - 0.15 <= rin.position.x + 2)
    {
        ball1.position.x += spee;
        if(ball1.position.x-0.35<rin.position.x)
        { 
            spee += 0.002;
            addy = 1.1;
        }
        else
        {
            spee -= 0.002;
            addy = 1.2;
        }
        if(ball1.position.x-0.35>rin.position.x+1)
            addy = 1.4;
        ball1.position.y = addy - sqrt(4 - (ball1.position.x - rin.position.x - 0.35)*(ball1.position.x - rin.position.x - 0.35));
        bon[bon_ind].position.x = ball1.position.x;
        bon[bon_ind].position.y = (ball1.position.y - 0.55);
        draw();
        glfwSwapBuffers(window);
    }
    ball1.jump = 1;
    if(ball1.yspeed == 0)
        ball1.yspeed = 0.1;
    else
        ball1.yspeed = 0 - ball1.yspeed;
    return;

}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset){
    if(yoffset > 0 || xoffset > 0)
    {
        screen_zoom += 0.003;
        reset_screen();
    }
    else if(yoffset < 0 || xoffset < 0)
    {
        screen_zoom -= 0.003;
        reset_screen();
    }
}


void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
