// variable setup
bool moved=FALSE;   //initialize flag that indicates if box was moved
int n=0;            //initialize counter for waiting period after box moved
int trigger_pin=D1; //designate digital pin1 for trigger input 
int led=D7;         //designates digital pin7 for LED

void setup() {
    pinMode(led,OUTPUT);
    pinMode(trigger_pin,INPUT);
    attachInterrupt(trigger_pin,itMoved,RISING);
    digitalWrite(led,LOW);
}

void loop() {
    if (moved) {
        digitalWrite(led,HIGH);
        n++;
        delay(100);
        if (n>30) {
            digitalWrite(led,LOW);
            moved=FALSE;
            n=0;
        }
    }

}

void itMoved() {
    moved=TRUE;
}
