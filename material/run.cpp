//This example program is created by thecplusplusuy for demonstration purposes. It's a simple 3D model loader (wavefront (.obj)), which is capable to load materials and UV textures:
//http://www.youtube.com/user/thecplusplusguy
//Free source, modify if you want, LGPL licence (I guess), I would be happy, if you would not delete the link
//so other people can see the tutorial
//this file is third.cpp an example, how to use the class
#include "object_3d.cpp"
 
float angle=0.0, ball_z;
 
int cube, ball, bottle, surface;
objloader obj;  //create an instance of the objloader
void init()
{
        glClearColor(1.0,1.0,1.0,1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,640.0/480.0,1.0,500.0);
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);
        cube=obj.load("cube.obj");      
        ball=obj.load("ball.obj");    
        bottle=obj.load("bowling.obj");    
        surface = obj.load("woodyground.obj");
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        float col[]={1.0,1.0,1.0,1.0};
        glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
}
 
void display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        float pos[]={-1.0,1.0,-2.0,1.0};
        glLightfv(GL_LIGHT0,GL_POSITION,pos);
        glTranslatef(0.0,-3.0,-20.0);
        glRotatef(angle, 0.0, 1.0, 0.0);
        glCallList(cube);       //and display it
        glTranslatef(3.0,0.0,0.0);
        glCallList(bottle);
        glLoadIdentity();

        
}
 
 
int main(int argc,char** argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface* screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);
        bool running=true;
        Uint32 start;
        SDL_Event event;
        init();
        while(running)
        {
                start=SDL_GetTicks();
                while(SDL_PollEvent(&event))
                {
                        switch(event.type)
                        {
                                case SDL_QUIT:
                                        running=false;
                                        break;
                        }
                }
                display();
                SDL_GL_SwapBuffers();
                angle+=0.5;
                if(angle>360)
                        angle-=360;
                if(1000/30>(SDL_GetTicks()-start))
                        SDL_Delay(1000/30-(SDL_GetTicks()-start));
        }
        SDL_Quit();
        return 0;      
}

/*
// bottles
        // glPushMatrix();

        //     glScalef(0.3, 0.3, 0.3);
        //     glTranslatef(-9.0,-4.0,-50.0);
        //     glCallList(bottle);       //draw the 3D mesh
        //     glTranslatef(4.0, 0.0,0.0);
        //     glCallList(bottle);       //draw the 3D mesh
        //     glTranslatef(4.0, 0.0,0.0);
        //     glCallList(bottle);       //draw the 3D mesh
        //     glTranslatef(4.0, 0.0,0.0);
        //     glCallList(bottle);       //draw the 3D mesh

        //     glTranslatef(-10.0, 0.0,6.0);
        //     glCallList(bottle);       //draw the 3D mesh
        //     glTranslatef(4.0, 0.0,0.0);
        //     glCallList(bottle);       //draw the 3D mesh
        //     glTranslatef(4.0, 0.0,0.0);
        //     glCallList(bottle);       //draw the 3D mesh

        //     glTranslatef(-6.0, 0.0,6.0);
        //     glCallList(bottle);       //draw the 3D mesh
        //     glTranslatef(4.0, 0.0,0.0);
        //     glCallList(bottle);       //draw the 3D mesh

        //     glTranslatef(-2.0, 0.0,6.0);
        //     glCallList(bottle);       //draw the 3D mesh

        // glPopMatrix();

        // ball
        // glPushMatrix();
            
        //     glScalef(0.3,0.3,0.3);
        //     glTranslatef(-4.0,-4.0,8.0-ball_z);
        //     glCallList(ball);       //draw the 3D mesh
        
        // glPopMatrix();

        // // surface
        // glPushMatrix();
            
        //     glScalef(0.35, 1.0, 2.0);
        //     glTranslatef(-2,-3.0,-10.0);
        //     glCallList(surface);       //draw the 3D mesh
        
        // glPopMatrix();

        angle+=0.5;
        if(angle>360)angle-=360;

        ball_z+=0.1;
        if(ball_z>=25)ball_z = 0;

*/