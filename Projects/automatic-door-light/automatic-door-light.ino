// Code by Jym Patel || it uses GPL v3 License
// get it at github https://github.com/JymPatel/megauno-ArduinoHere


// Define where the Pins are
#define echoPin 3
#define trigPin 4
#define ledPin 2

// variables we need
long duration;
int distance;

// create setup
void setup()
{
    // specify weather it's output device or input
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    // get serial monitor for readings
    Serial.begin(9600);
}
void loop()
{
    // clean waves by setting trigPin as LOW
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // launch Ultrasonic Waves
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // measure time it takes to get back, also get distance
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    // make ledPin HIGH if distance is too far.
    if (distance >= 20)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}
