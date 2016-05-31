import processing.serial.*; /* Needed for Serial Communication */

/* Global variables */
Serial comPort;
String [] comPortList;
String comPortString;

/*--------------------------------------------------*/

void setup(){
  size(100,100);            /* Set the size of the window  */
  background(0);            /* Set the background to black */
  
  
  /* Get the available com ports. If there is at least one
     com port available, then start communicating on it.
     If there are more than one com ports available, we will
     only open the first one (i.e. comPortList[0])
     The bufferUntil('\n'); statement will generate a serial Event
     when it reads a carriage return */
     
  comPortList = Serial.list();  
  if(comPortList.length>0){
    comPort = new Serial(this, comPortList[0], 9600);
    comPort.bufferUntil('\n');
  }
}

/*--------------------------------------------------*/

void draw(){
  /* The serialEvent function will update the display */
  delay(7000);
}

/*--------------------------------------------------*/

void serialEvent(Serial cPort){
  comPortString = cPort.readStringUntil('\n');
  if(comPortString != null) {
    comPortString=trim(comPortString);
    
    /* Print to the Debug screen in Processing IDE */
    println(comPortString);
    
    /* Send Data to Server */
    if(comPortString.equals("1") = true) {
      String sendData[] = loadStrings("http://rfidvoting.tk/process.php?card=1");
    } else {
      String sendData[] = loadStrings("http://rfidvoting.tk/process.php?card=0");  
    }
  }
}