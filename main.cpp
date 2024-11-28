#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

const int WIDTH = 800;
const int HEIGHT = 600;

void display();
void reshape(int, int);
void timer(int);

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color
    glEnable(GL_DEPTH_TEST);         // Enable depth testing
}



int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(WIDTH, HEIGHT);

    glutCreateWindow("jajaga");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000, timer, 0);
    init();

    glutMainLoop();

}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -15.0);
    glRotatef(35, 1.0, 1.0, 1.0);

    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);  


    // Back face
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);  


    // Top face
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Bottom face
    glColor3f(1.0,  
 1.0, 0.0); // Yellow
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    // Left face  

    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);  


    // Right face
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    glEnd();

    glutSwapBuffers();
}


void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w/(float)h, 0.1, 100);

}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}
