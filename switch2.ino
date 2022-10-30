#include <Ethernet.h>
#include <string.h>
// #define one {1,1,0}
// static const char digits[] = {
//     0x111, 0x011, 0x101, 0x100, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39
// };
int sw_1 = 34;
int sw_2 = 26;
int sw_4 = 35;
int buf[3],//新讀到的值
    prebuf[3];//上一次的值
int zero[3] = {1, 1, 1},
    one[3] = {1, 1, 0},
    two[3] = {1, 0, 1},
    three[3] = {1, 0, 0},
    four[3] = {0, 1, 1},
    five[3] = {0, 1, 0},
    six[3] = {0, 0, 1},
    seven[3] = {0, 0, 0};
void setup()
{
    Serial.begin(115200);
    pinMode(sw_1, INPUT); // sw_1
    pinMode(sw_2, INPUT); // sw_2
    pinMode(sw_4, INPUT); // sw_4

    buf[0] = digitalRead(sw_4);
    buf[1] = digitalRead(sw_2);
    buf[2] = digitalRead(sw_1);//buf 110
    prebuf[0]=buf[0];
    prebuf[1]=buf[1];
    prebuf[2]=buf[2];//prebuf 110
    
    if (memcmp(buf, zero, sizeof(buf))==0){Serial.println("0");}
    else if(memcmp(buf, one, sizeof(buf))==0){Serial.println("1");}
    else if(memcmp(buf, two, sizeof(buf))==0){Serial.println("2");}
    else if(memcmp(buf, three, sizeof(buf))==0){Serial.println("3");}
    else if(memcmp(buf, four, sizeof(buf))==0){Serial.println("4");}
    else if(memcmp(buf, five, sizeof(buf))==0){Serial.println("5");}
    else if(memcmp(buf, six, sizeof(buf))==0){Serial.println("6");}
    else if(memcmp(buf, seven, sizeof(buf))==0){Serial.println("7");}
    
}

void loop()
{
    buf[0] = digitalRead(sw_4);
    buf[1] = digitalRead(sw_2);
    buf[2] = digitalRead(sw_1);//buf 111

    if(memcmp(buf, prebuf, sizeof(buf))!=0){
        prebuf[0]=buf[0];
        prebuf[1]=buf[1];
        prebuf[2]=buf[2];
        if (memcmp(buf, zero, sizeof(buf))==0){Serial.println("0");}
        else if(memcmp(buf, one, sizeof(buf))==0){Serial.println("1");}
        else if(memcmp(buf, two, sizeof(buf))==0){Serial.println("2");}
        else if(memcmp(buf, three, sizeof(buf))==0){Serial.println("3");}
        else if(memcmp(buf, four, sizeof(buf))==0){Serial.println("4");}
        else if(memcmp(buf, five, sizeof(buf))==0){Serial.println("5");}
        else if(memcmp(buf, six, sizeof(buf))==0){Serial.println("6");}
        else if(memcmp(buf, seven, sizeof(buf))==0){Serial.println("7");}
    }
    delay(5000);

}
