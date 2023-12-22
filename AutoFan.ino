// Put initial variables here

// Put method to turn on and off fan here

//Temp method here

//Humidity method here

//Put detection method here that checks tempurature/humidity in their methods

//Optional methods here that control buttons, lights, and/or screens

//Make sure to add timeout stuff when necessary


//Code from dht example (uno ultimate starter kit)

// #include <dht_nonblocking.h>

// //www.elegoo.com
// //2018.10.25


// #include <dht_nonblocking.h>
// #define DHT_SENSOR_TYPE DHT_TYPE_11

// static const int DHT_SENSOR_PIN = 2;
// DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );



// /*
//  * Initialize the serial port.
//  */
// void setup( )
// {
//   Serial.begin( 9600);
// }



// /*
//  * Poll for a measurement, keeping the state machine alive.  Returns
//  * true if a measurement is available.
//  */
// static bool measure_environment( float *temperature, float *humidity )
// {
//   static unsigned long measurement_timestamp = millis( );

//   /* Measure once every four seconds. */
//   if( millis( ) - measurement_timestamp > 3000ul )
//   {
//     if( dht_sensor.measure( temperature, humidity ) == true )
//     {
//       measurement_timestamp = millis( );
//       return( true );
//     }
//   }

//   return( false );
// }



// /*
//  * Main program loop.
//  */
// void loop( )
// {
//   float temperature;
//   float humidity;

//   /* Measure temperature and humidity.  If the functions returns
//      true, then a measurement is available. */
//   if( measure_environment( &temperature, &humidity ) == true )
//   {
//     Serial.print( "T = " );
//     Serial.print( temperature, 1 );
//     Serial.print( " deg. C, H = " );
//     Serial.print( humidity, 1 );
//     Serial.println( "%" );
//   }
// }


//Code from dc motor example (uno ultimate starter kit)

// /************************
// Exercise the motor using
// the L293D chip
// ************************/

// #define ENABLE 5
// #define DIRA 3
// #define DIRB 4

// int i;
 
// void setup() {
//   //---set pin direction
//   pinMode(ENABLE,OUTPUT);
//   pinMode(DIRA,OUTPUT);
//   pinMode(DIRB,OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   //---back and forth example
//     Serial.println("One way, then reverse");
//     digitalWrite(ENABLE,HIGH); // enable on
//     for (i=0;i<5;i++) {
//     digitalWrite(DIRA,HIGH); //one way
//     digitalWrite(DIRB,LOW);
//     delay(500);
//     digitalWrite(DIRA,LOW);  //reverse
//     digitalWrite(DIRB,HIGH);
//     delay(500);
//   }
//   digitalWrite(ENABLE,LOW); // disable
//   delay(2000);

//   Serial.println("fast Slow example");
//   //---fast/slow stop example
//   digitalWrite(ENABLE,HIGH); //enable on
//   digitalWrite(DIRA,HIGH); //one way
//   digitalWrite(DIRB,LOW);
//   delay(3000);
//   digitalWrite(ENABLE,LOW); //slow stop
//   delay(1000);
//   digitalWrite(ENABLE,HIGH); //enable on
//   digitalWrite(DIRA,LOW); //one way
//   digitalWrite(DIRB,HIGH);
//   delay(3000);
//   digitalWrite(DIRA,LOW); //fast stop
//   delay(2000);

//   Serial.println("PWM full then slow");
//   //---PWM example, full speed then slow
//   analogWrite(ENABLE,255); //enable on
//   digitalWrite(DIRA,HIGH); //one way
//   digitalWrite(DIRB,LOW);
//   delay(2000);
//   analogWrite(ENABLE,180); //half speed
//   delay(2000);
//   analogWrite(ENABLE,128); //half speed
//   delay(2000);
//   analogWrite(ENABLE,50); //half speed
//   delay(2000);
//   analogWrite(ENABLE,128); //half speed
//   delay(2000);
//   analogWrite(ENABLE,180); //half speed
//   delay(2000);
//   analogWrite(ENABLE,255); //half speed
//   delay(2000);
//   digitalWrite(ENABLE,LOW); //all done
//   delay(10000);
// }