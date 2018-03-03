#include <math.h>
class Vector {
    public:
      float x;
      float y;
      float z;
      Vector(){
        x=y=0.0;
      }

      Vector(Vector* a){
        this->x = a->x;
        this->y =a->y;
      }
      
      
      Vector(float value){
        x=y=value;
      }
      
      void normalize(){
       float mag = sqrt(x*x + y*y );
        if(mag == 0){
            return;
        }
        x /= mag;
        y /= mag;
      }
      
      void scale(float a){
        x*=a;
        y*=a;
  
    }

    void add(const Vector& a){
        x += a.x;
        y += a.y;
    
    }

    void subtract(const Vector& a){
        x -= a.x;
        y -= a.y;

    }

    float dot(const Vector& a){
        return (x * a.x + y * a.y );
    }

    float mod(){
        return sqrt(x * x + y * y );
    }


    void comp(float& a, float& b){
        a = x;
        b = y;
    }

    void comp(Vector& a){
        a.x = x;
        a.y = y;
  
    }
};
      