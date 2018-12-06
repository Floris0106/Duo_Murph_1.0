void setup() 
{
  int hBridgePins[4] = {};
  for (int i = 0; i <= 4; i++)
  {
    pinMode(hBridgePins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() 
{
  
}

public void hBrigeWrite (char motor, int motorDirection) 
{
  if (motor == 'A')
  {
    switch (motorDirection) 
    {
      case 0:
        digitalWrite(hBridgePins[1], LOW);
        digitalWrite(hBridgePins[2], LOW);
        Serial.println("SUCCES");
        break;
      case 1:
        digitalWrite(hBridgePins[1], HIGH);
        digitalWrite(hBridgePins[2], LOW);
        Serial.println("SUCCES");
        break;
      case -1:
        digitalWrite(hBridgePins[1], LOW);
        digitalWrite(hBridgePins[2], HIGH);
        Serial.println("SUCCES");
        break;
      case default:
        Serial.println("ERR_INVALID_DIRECTION");
        break;
    }
  } else if (motor == 'B')
  {
    switch (motorDirection) 
    {
      case 0:
        digitalWrite(hBridgePins[3], LOW);
        digitalWrite(hBridgePins[4], LOW);
        Serial.println("SUCCES");
        break;
      case 1:
        digitalWrite(hBridgePins[3], HIGH);
        digitalWrite(hBridgePins[4], LOW);
        Serial.println("SUCCES");
        break;
      case -1:
        digitalWrite(hBridgePins[3], LOW);
        digitalWrite(hBridgePins[4], HIGH);
        Serial.println("SUCCES");
        break;
      case default:
        Serial.println("ERR_INVALID_DIRECTION");
        break;
    }
  } else
  {
    Serial.println("ERR_INVALID_MOTOR");
  }
}

public void driveForward (char driveDirection)
{
  switch (driveDirection) 
  {
    case S:
      hBridgeWrite('A', 0);
      hBridgeWrite('B', 0);
      break;
    case F:
      hBridgeWrite('A', 1);
      hBridgeWrite('B', 1);
      break;
    case L:
      hBridgeWrite('A', 0);
      hBridgeWrite('B', 1);
      break;
    case R:
      hBridgeWrite('A', 1);
      hBridgeWrite('B', 0);
      break;
    case default:
      Serial.println("ERR_INVALID_DIRECTION");
      break;
  }
}

public void driveBackward (char driveDirection)
{
  switch (driveDirection) 
  {
    case S:
      hBridgeWrite('A', 0);
      hBridgeWrite('B', 0);
      break;
    case B:
      hBridgeWrite('A', -1);
      hBridgeWrite('B', -1);
      break;
    case L:
      hBridgeWrite('A', -1);
      hBridgeWrite('B', 0);
      break;
    case R:
      hBridgeWrite('A', 0);
      hBridgeWrite('B', -1);
      break;
    case default:
      Serial.println("ERR_INVALID_DIRECTION");
      break;
  }
}

public void turnOnSpot (char turnDirection)
{
  switch (turnDirection)
  {
    case L:
      hBridgeWrite('A', -1);
      hBridgeWrite('B', 1);
    case R:
      hBridgeWrite('A', 1);
      hBridgeWrite('B', -1);
    case default:
      Serial.println("ERR_INVALID_DIRECTION");
      break;
  }
}
