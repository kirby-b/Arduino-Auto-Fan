/************************
Exercise the motor using
the L293D chip
************************/
#include <dht_nonblocking.h>
//Initializing Variables

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define ENABLE 5
#define DIRA 3
#define DIRB 4
static const int DHT_SENSOR_PIN = 2;
int i;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

/*
 * Initialize the serial port.
 */
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}
/*
 * Poll for a measurement, keeping the state machine alive.  Returns
 * true if a measurement is available.
 */
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}

/*
 * Main program loop.
 */
void loop( )
{
  float temperature;
  float humidity;

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if( measure_environment( &temperature, &humidity ) == true )
  { 
    //Prints out temp and humidity around the sensor
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
    if(temperature >= 75 || humidity >= 100 ){ //Should in theory turn on the fan if the temp is higher than 75 or if humidity is higher than 100%
        Serial.println("Activating Fan..");
        analogWrite(ENABLE,255); //enable on
        digitalWrite(DIRA,255);
        digitalWrite(DIRB,LOW);
        Serial.println("Fan on");
        delay(240000);
        digitalWrite(ENABLE,LOW); //all done
    }
  }
}
