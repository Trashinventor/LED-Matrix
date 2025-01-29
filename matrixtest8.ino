//*************************************************
//  --------------LED-MATRIX-DRIVER--------------  
//  by Moritz Rambold 2025 - thetrashinventor.de  
//*************************************************

#include <avr/pgmspace.h>
#include <EEPROM.h>

//All Symbols for this Font
struct Font {
  //Letters
   static const byte A[6] PROGMEM;          //A
   static const byte B[6] PROGMEM;          //B
   static const byte C[6] PROGMEM;          //C
   static const byte D[6] PROGMEM;          //D
   static const byte E[6] PROGMEM;          //E
   static const byte F[6] PROGMEM;          //F
   static const byte G[6] PROGMEM;          //G
   static const byte H[6] PROGMEM;          //H
   static const byte I[6] PROGMEM;          //I
   static const byte J[6] PROGMEM;          //J   
   static const byte K[6] PROGMEM;          //K
   static const byte L[6] PROGMEM;          //L
   static const byte M[6] PROGMEM;          //M
   static const byte N[6] PROGMEM;          //N
   static const byte O[6] PROGMEM;          //O
   static const byte P[6] PROGMEM;          //P
   static const byte Q[6] PROGMEM;          //Q
   static const byte R[6] PROGMEM;          //R
   static const byte S[6] PROGMEM;          //S
   static const byte T[6] PROGMEM;          //T
   static const byte U[6] PROGMEM;          //U
   static const byte V[6] PROGMEM;          //V
   static const byte W[6] PROGMEM;          //W
   static const byte X[6] PROGMEM;          //X
   static const byte Y[6] PROGMEM;          //Y
   static const byte Z[6] PROGMEM;          //Z

  //Numbers
   static const byte n1[6] PROGMEM;         //1
   static const byte n2[6] PROGMEM;         //2
   static const byte n3[6] PROGMEM;         //3
   static const byte n4[6] PROGMEM;         //4
   static const byte n5[6] PROGMEM;         //5
   static const byte n6[6] PROGMEM;         //6
   static const byte n7[6] PROGMEM;         //7
   static const byte n8[6] PROGMEM;         //8
   static const byte n9[6] PROGMEM;         //9
   static const byte n0[6] PROGMEM;         //0

  //Symbols etc.
  static const byte ex[6] PROGMEM;          // !
  static const byte sp[6] PROGMEM;          //  (SPACE)
  static const byte quest[6] PROGMEM;       // ?
  static const byte colon[6] PROGMEM;       // :
  static const byte under[6] PROGMEM;       // _
  static const byte dash[6] PROGMEM;        // -
  static const byte slash[6] PROGMEM;       // /
  static const byte backslash[6] PROGMEM;   // (BACKSLASH)
  static const byte plus[6] PROGMEM;        // +
  static const byte aster[6] PROGMEM;       // *
  static const byte dot[6] PROGMEM;         // .
  static const byte equ[6] PROGMEM;         // =
  static const byte brackopen[6] PROGMEM;   // [
  static const byte brackclose[6] PROGMEM;  // ]
  static const byte omega[6] PROGMEM;       // Ω
  static const byte greater[6] PROGMEM;     // >
  static const byte less[6] PROGMEM;        // <
  static const byte semicol[6] PROGMEM;     // ;
  static const byte percent[6] PROGMEM;     // %
  static const byte hash[6] PROGMEM;        // #
  static const byte symboland[6] PROGMEM;   // &
  static const byte quote[6] PROGMEM;       // "
  static const byte apos[6] PROGMEM;        // '
  static const byte tilde[6] PROGMEM;       // ~
  static const byte vertbar[6] PROGMEM;     // |
  static const byte deg[6] PROGMEM;         // °
  static const byte dollar[6] PROGMEM;      // $
  static const byte fullblock[6] PROGMEM;   // ▓ 
  static const byte semiblock[6] PROGMEM;   // ▒ 
  static const byte lightblock[6] PROGMEM;  // ░ 
  static const byte heart[6] PROGMEM;       // ♥
  static const byte spades[6] PROGMEM;      // ♠
  static const byte dia[6] PROGMEM;         // ♦
  static const byte clubs[6] PROGMEM;       // ♣
  static const byte brkrndopen[6] PROGMEM;  // (
  static const byte brkrndclose[6] PROGMEM; // )
  static const byte brkcurlopen[6] PROGMEM; // {
  static const byte brkcurlclose[6] PROGMEM;// }
  static const byte germansz[6] PROGMEM;    // ß
  static const byte micro[6] PROGMEM;       // µ
  static const byte arrup[6] PROGMEM;       // ↑
  static const byte arrdown[6] PROGMEM;     // ↓ 
  static const byte arrright[6] PROGMEM;    // → 
  static const byte arrleft[6] PROGMEM;     // ← 
} font;

//Definition of Symbols
//Letters
const byte Font::A[6] PROGMEM = {B10001000, B10001000, B10001000, B11111000, B10001000, B01110000};
const byte Font::B[6] PROGMEM = {B11110000, B10001000, B10001000, B11110000, B10001000, B11110000};
const byte Font::C[6] PROGMEM = {B01110000, B10000000, B10000000, B10000000, B10000000, B01110000};
const byte Font::D[6] PROGMEM = {B11110000, B10001000, B10001000, B10001000, B10001000, B11110000};
const byte Font::E[6] PROGMEM = {B11110000, B10000000, B10000000, B11110000, B10000000, B11110000};
const byte Font::F[6] PROGMEM = {B10000000, B10000000, B10000000, B11110000, B10000000, B11110000};
const byte Font::G[6] PROGMEM = {B01110000, B10001000, B10001000, B10111000, B10000000, B01110000};
const byte Font::H[6] PROGMEM = {B10001000, B10001000, B10001000, B11111000, B10001000, B10001000};
const byte Font::I[6] PROGMEM = {B11100000, B01000000, B01000000, B01000000, B01000000, B11100000};
const byte Font::J[6] PROGMEM = {B01100000, B10010000, B00010000, B00010000, B00010000, B11110000};
const byte Font::K[6] PROGMEM = {B10001000, B10010000, B10100000, B11100000, B10010000, B10001000};
const byte Font::L[6] PROGMEM = {B11110000, B10000000, B10000000, B10000000, B10000000, B10000000};
const byte Font::M[6] PROGMEM = {B10001000, B10001000, B10001000, B10101000, B11011000, B10001000};
const byte Font::N[6] PROGMEM = {B10001000, B10011000, B10111000, B11101000, B11001000, B10001000};
const byte Font::O[6] PROGMEM = {B01110000, B10001000, B10001000, B10001000, B10001000, B01110000};
const byte Font::P[6] PROGMEM = {B10000000, B10000000, B10000000, B11110000, B10001000, B11110000};
const byte Font::Q[6] PROGMEM = {B01101000, B10010000, B10101000, B10001000, B10001000, B01110000};
const byte Font::R[6] PROGMEM = {B10001000, B10010000, B10100000, B11110000, B10001000, B11110000};
const byte Font::S[6] PROGMEM = {B11110000, B00001000, B00001000, B01110000, B10000000, B01111000};
const byte Font::T[6] PROGMEM = {B00100000, B00100000, B00100000, B00100000, B00100000, B11111000};
const byte Font::U[6] PROGMEM = {B01110000, B10001000, B10001000, B10001000, B10001000, B10001000};
const byte Font::V[6] PROGMEM = {B00100000, B01010000, B01010000, B10001000, B10001000, B10001000};
const byte Font::W[6] PROGMEM = {B10001000, B11011000, B10101000, B10001000, B10001000, B10001000};
const byte Font::X[6] PROGMEM = {B10001000, B01010000, B00100000, B00100000, B01010000, B10001000};
const byte Font::Y[6] PROGMEM = {B00100000, B00100000, B00100000, B00100000, B01010000, B10001000};
const byte Font::Z[6] PROGMEM = {B11111000, B11000000, B01100000, B00110000, B00011000, B11111000};

//Numbers
const byte Font::n1[6] PROGMEM = {B00010000, B00010000, B00010000, B10010000, B01010000, B00110000};
const byte Font::n2[6] PROGMEM = {B11111000, B01000000, B00100000, B00010000, B10001000, B01110000};
const byte Font::n3[6] PROGMEM = {B11110000, B00001000, B00001000, B01110000, B00001000, B11110000};
const byte Font::n4[6] PROGMEM = {B00010000, B00010000, B11111000, B10010000, B10010000, B10000000};
const byte Font::n5[6] PROGMEM = {B11110000, B00001000, B00001000, B11110000, B10000000, B11111000};
const byte Font::n6[6] PROGMEM = {B01110000, B10001000, B10001000, B11110000, B10000000, B01111000};
const byte Font::n7[6] PROGMEM = {B00100000, B00100000, B00010000, B00010000, B00001000, B11111000};
const byte Font::n8[6] PROGMEM = {B01110000, B10001000, B10001000, B01110000, B10001000, B01110000};
const byte Font::n9[6] PROGMEM = {B01000000, B00100000, B00010000, B01111000, B10001000, B01110000};
const byte Font::n0[6] PROGMEM = {B01110000, B11001000, B11101000, B10111000, B10011000, B01110000};

//Symbols etc.
const byte Font::ex[6] PROGMEM = {B10000000, B00000000, B10000000, B10000000, B10000000, B10000000};
const byte Font::sp[6] PROGMEM = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};
const byte Font::dot[6] PROGMEM = {B10000000, B00000000, B00000000, B00000000, B00000000, B00000000};
const byte Font::colon[6] PROGMEM = {B00000000, B10000000, B00000000, B00000000, B10000000, B00000000};
const byte Font::under[6] PROGMEM = {B11111000, B00000000, B00000000, B00000000, B00000000, B00000000};
const byte Font::dash[6] PROGMEM = {B00000000, B00000000, B00000000, B01110000, B00000000, B00000000};
const byte Font::plus[6] PROGMEM = {B00000000, B00100000, B00100000, B11111000, B00100000, B00000000};



#define RX_PIN 0        // Arduino RX (to HC05 TX)
#define TX_PIN 1        // Arduino TX (to HC05 RX)
#define BAUD_RATE 9600  // HC05 default baud rate

int latchPin = 10;
int clockPin = 13;
int dataPin = 11;
int clock = 9;
int Reset = 8;
int latchPinPORTB = latchPin - 8;
int clockPinPORTB = clockPin - 8;
int dataPinPORTB = dataPin - 8;
int i = 0;

byte bufferArray[6][3] = {0};                 // Actual buffer array for the display (6 rows, 3 bytes per row)
byte temporaryBuffer[6][3] = {0};             // Temporary buffer to hold character data before updating
bool updateDisplay = false;                   // Flag to control whether the display is updated
int scrollSpeed = 100;                        // Speed of scrolling in milliseconds
String lastText = "";                         // Store the last received text
const int EEPROM_SIZE = EEPROM.length();      // Size of EEPROM
const int SPEED_ADDRESS = EEPROM_SIZE - 1;    // Store the speed at last possible address to maximize memory for text
bool scrollingActive = true;                  // Flag to check if scrolling is active

//Prototypes
void displayString(const char* , int );
void scrollText(const char* , int ,int);
const byte* getMapping(char);
uint8_t getWidth(char);
String readFromEEPROM();
void saveToEEPROM(const char*);
void processReceivedCommand(const String&);
void saveSpeedToEEPROM(int);
int readSpeedFromEEPROM();
void help();
void ani1();

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(Reset, OUTPUT);

  digitalWrite(Reset, HIGH);
  digitalWrite(Reset, LOW);

  setupSPI();
  Serial.begin(BAUD_RATE); 
  scrollSpeed = readSpeedFromEEPROM();

  // Display saved text from EEPROM
  String savedText = readFromEEPROM();
  lastText = readFromEEPROM();
  if (savedText.length() > 0) {
    scrollText(savedText.c_str(), 0, scrollSpeed); // Scroll saved text
  }
}

// Function to display a character from the font (update only the temporary buffer)
void displayCharacter(const byte character[6], int startX) {
  // Map the character into the temporaryBuffer without restricting to the display width
  for (int row = 0; row < 6; row++) {
    byte rowData = pgm_read_byte(&character[row]);                  // Correctly read from PROGMEM
    for (int bit = 0; bit < 8; bit++) {
      int x = startX + bit;                                         // Calculate the column index
      if (x >= 0 && x < 24) {                                       // Ensure pixel stays within buffer bounds
        int byteIndex = x / 8;                                      // Determine the byte index in temporaryBuffer
        int bitIndex = x % 8;                                       // Determine the bit index within the byte
        if (rowData & (1 << (7 - bit))) {                           // Reverse bit order (MSB to LSB)
          temporaryBuffer[5 - row][byteIndex] |= (1 << bitIndex);   // Map bottom-to-top row order
        }
      }
    }
  }
  updateDisplay = true;  // Mark that the display needs to be updated
}

// Function to trigger an update (copy temporary buffer to actual buffer and send data to display)
void displayUpdate() {
  if (updateDisplay) {                                            // Only update if the flag is set
    memcpy(bufferArray, temporaryBuffer, sizeof(bufferArray));    // Copy contents of temporary buffer into the actual buffer
    displayBuffer(bufferArray);                                   // Now update the display with the new buffer
    updateDisplay = false;                                        // Reset the flag after updating
  }
}

// Function to clear the display (set all pixels to 0 in the temporary buffer)
void displayClear() {
  // Clear the temporaryBuffer
  for (int row = 0; row < 6; row++) {
    for (int col = 0; col < 3; col++) {
      temporaryBuffer[row][col] = 0;
    }
  }
  updateDisplay = true;   // Mark that the display needs to be updated
  displayUpdate();        // Immediately update the display after clearing
}

// Function to display the buffer (send data to the display)
void displayBuffer(byte buffer[][3]) {
  for (int y = 0; y < 6; y++) {           // Loop through each row
    if (i == 6) {                         // Reset 4017 counter if needed
      digitalWrite(Reset, HIGH);
      digitalWrite(Reset, LOW);
      i = 0;
    }
    latchOff();
    // Send all three bytes for the current row
    spi_transfer(buffer[y][2]);
    spi_transfer(buffer[y][1]);
    spi_transfer(buffer[y][0]);
    latchOn();
    delayMicroseconds(800);     // Delay for display stability

    latchOff();
    spi_transfer(0);            // Clear data
    spi_transfer(0);
    spi_transfer(0);
    latchOn();

    digitalWrite(clock, HIGH);  // Increment the 4017 counter
    digitalWrite(clock, LOW);
    i++;
  }
}

void loop() {
  if (Serial.available()) {                             // Check if data is available from Bluetooth
    String receivedText = Serial.readStringUntil('\n'); // Read until newline character
    receivedText.trim();                                // Remove any trailing newline or spaces
    processReceivedCommand(receivedText);               // Process the received command or text
  }

  // Continuously scroll the last text
  if (!lastText.length() > 0) {
    scrollText(lastText.c_str(), 0, scrollSpeed);
  }
}

void latchOn() {
  bitSet(PORTB, latchPinPORTB);
}

void latchOff() {
  bitClear(PORTB, latchPinPORTB);
}

void setupSPI() {
  byte clr;
  SPCR |= ((1 << SPE) | (1 << MSTR));                         // Enable SPI as master
  SPCR &= ~((1 << SPR1) | (1 << SPR0));                       // Set prescaler bits to fastest
  clr = SPSR;                                                 // Clear SPI status register
  clr = SPDR;                                                 // Clear SPI data register
  SPSR |= (1 << SPI2X);                                       // Enable double SPI speed
}

byte spi_transfer(byte data) {
  SPDR = data;                                                // Start the transmission
  while (!(SPSR & (1 << SPIF)));                              // Wait for transmission to complete
  return SPDR;                                                // Return received byte (not used here)
}

//display text static
void displayString(const char* str, int startX) {
  int currentX = startX;                                      // Initialize the starting X position for the string
  
  for (int i = 0; str[i] != '\0'; i++){                       // Loop through each character in the string
    char currentChar = str[i];                                // Get the current character
    const byte* characterData = nullptr;                      // Select the corresponding font data based on the character
    characterData = getMapping( currentChar);

    if (characterData != nullptr) {                           // If valid character data was found, display it
      displayCharacter(characterData, currentX);              // Display the character in the temporary buffer
      currentX += getWidth(str[i]) + 1;                       // Move to the next character's position
    }
  }
  displayUpdate();
}

// Function to scroll the text over the display
void scrollText(const char* str, int startX, int scrollSpeed){
  int textWidth = 0;                                      // Variable to store the total text width
  int currentX = startX;                                  // Initial x-position of the text
  unsigned long lastScrollTime = 0;                        // Timestamp of the last scroll update

  // Calculate the total width of the text based on individual character widths and add 1 pixel gap between characters
  for (int i = 0; str[i] != '\0'; i++) {
    textWidth += getWidth(str[i]) + 1;                     // Add the width of each character and 1 pixel for the gap
  }
  textWidth--; // Subtract 1 pixel at the end because there's no need for extra gap after the last character

  while (Serial.available() == false){

    unsigned long currentTime = millis();                  // Get the current time
    displayClear();

    if (currentTime - lastScrollTime >= scrollSpeed) {     // Check if it's time to scroll
      currentX--;                                          // Update the x-position for scrolling
      lastScrollTime = currentTime;                         // Reset the timestamp
      
      if (currentX < -textWidth) {                          // Wrap around when the text scrolls off the screen
        currentX = 24;                                      // Reset to start position (off-screen to the right)
      }
    }

    int charXPos = currentX; // Initialize the position of the first character
    for (int i = 0; str[i] != '\0'; i++) {                  // Render each character at its respective position
      char currentChar = str[i];
      const byte* characterData = nullptr;
      characterData = getMapping(currentChar);              // Map the character to its font data

      if (characterData != nullptr) {                       // Skip invalid characters
        displayCharacter(characterData, charXPos);          // Write the character to the display at charXPos
      }
      charXPos += getWidth(str[i]) + 1;                     // Move to the next position for the next character, adding the width of the current character and 1 pixel for the gap
    }
    displayUpdate();                                        // Update the display with the new frame
  }
}

//Get the corresponding character-matrix
const byte* getMapping(char decodechar) {
  // Lookup table for mapping characters to their font data
  static const struct {
    char character;
    const byte* data;
  } lookupTable[] = {
    {'A', Font::A}, {'B', Font::B}, {'C', Font::C}, {'D', Font::D}, {'E', Font::E},
    {'F', Font::F}, {'G', Font::G}, {'H', Font::H}, {'I', Font::I}, {'J', Font::J},
    {'K', Font::K}, {'L', Font::L}, {'M', Font::M}, {'N', Font::N}, {'O', Font::O},
    {'P', Font::P}, {'Q', Font::Q}, {'R', Font::R}, {'S', Font::S}, {'T', Font::T},
    {'U', Font::U}, {'V', Font::V}, {'W', Font::W}, {'X', Font::X}, {'Y', Font::Y},
    {'Z', Font::Z}, 
    {'a', Font::A}, {'b', Font::B}, {'c', Font::C}, {'d', Font::D}, {'e', Font::E},
    {'f', Font::F}, {'g', Font::G}, {'h', Font::H}, {'i', Font::I}, {'j', Font::J},
    {'k', Font::K}, {'l', Font::L}, {'m', Font::M}, {'n', Font::N}, {'o', Font::O},
    {'p', Font::P}, {'q', Font::Q}, {'r', Font::R}, {'s', Font::S}, {'t', Font::T},
    {'u', Font::U}, {'v', Font::V}, {'w', Font::W}, {'x', Font::X}, {'y', Font::Y},
    {'z', Font::Z},
    {'1', Font::n1}, {'2', Font::n2}, {'3', Font::n3}, {'4', Font::n4},
    {'5', Font::n5}, {'6', Font::n6}, {'7', Font::n7}, {'8', Font::n8}, {'9', Font::n9},
    {'0', Font::n0}, 
    {'.', Font::dot}, {'!', Font::ex}, {' ', Font::sp}, {':', Font::colon}, 
    {'+', Font::plus}, {'_', Font::under}, {'-', Font::dash}// Add other symbols as needed
  };
  const size_t lookupTableSize = sizeof(lookupTable) / sizeof(lookupTable[0]);  // Number of entries in the lookup table

  // Search the table for the matching character
  for (size_t i = 0; i < lookupTableSize; i++) {
    if (lookupTable[i].character == decodechar) {
      return lookupTable[i].data;
    }
  }
  return nullptr;  // If character not found, return nullptr
}

// Function to save received text in EEPROM
void saveToEEPROM(const char* text) {
  int address = 0; // Start writing at EEPROM address 0
  for (int i = 0; text[i] != '\0'; i++) {
    if (address >= SPEED_ADDRESS) break; // Prevent overwriting the speed byte
    EEPROM.write(address++, text[i]);   // Write each character to EEPROM
  }
  if (address < SPEED_ADDRESS) {
    EEPROM.write(address, '\0'); // Add a null terminator to mark the end of the string
  }
}

// Function to read and return text from EEPROM
String readFromEEPROM() {
  String savedText = "";
  for (int address = 0; address < SPEED_ADDRESS; address++) {
    char ch = EEPROM.read(address); // Read a character from EEPROM
    if (ch == '\0') break;          // Stop reading at the null terminator
    savedText += ch;
  }
  return savedText;
}

// Function to save the speed value to EEPROM
void saveSpeedToEEPROM(int speed) {
  EEPROM.write(SPEED_ADDRESS, speed); // Save speed at the last EEPROM address
}

// Function to read the speed value from EEPROM
int readSpeedFromEEPROM() {
  int savedSpeed = EEPROM.read(SPEED_ADDRESS); // Read speed from last EEPROM address
  if (savedSpeed > 0) {                        // Ensure a valid speed value
    return savedSpeed;
  }
  return 10; // Default speed if no valid value is found
}

void processReceivedCommand(const String& command) {

  //set scrollspeed
  if (command.startsWith("@speed ")) {
    // Extract the speed value from the command
    int newSpeed = command.substring(7).toInt();          // Convert the text after "@speed " to an integer
    if (newSpeed > 0) {                                   // Ensure the speed is valid
      scrollSpeed = newSpeed;
      saveSpeedToEEPROM(scrollSpeed);                     // Save the new speed to EEPROM
      Serial.print("Scroll speed updated to: ");
      Serial.println(scrollSpeed);

      if (scrollingActive && lastText.length() > 0) {     // Resume scrolling the last text with the new speed if scrolling is active
        scrollText(lastText.c_str(), 0, scrollSpeed);
      }
    } 
    else {
      Serial.println("Invalid speed value.");
    }
  }

  //get help 
  else if (command.startsWith("@help")) {
    help();  
    if (scrollingActive && lastText.length() > 0) {         // Continue scrolling the last text if scrolling is active
      scrollText(lastText.c_str(), 0, scrollSpeed);         // Keep scrolling with the current speed
    }
  }

  //animation 1 
  else if (command.startsWith("@ani1")) {
    // Stop scrolling and display the animation
    scrollingActive = false;
    ani1();  // Call the animation function
    // Do not scroll text while animation is active
  }

  else {
    lastText = command;             // Save the text and update the display
    saveToEEPROM(lastText.c_str());
    Serial.println("Text saved to EEPROM!");
    scrollingActive = true;         // Switch back to scrolling the new text
    scrollText(lastText.c_str(), 0, scrollSpeed);
  }
}

// Help function to print helpful information to the serial monitor
void help() {
  Serial.println("HELP COMMANDS:");
  Serial.println("@speed <value>  - Set scrolling speed in ms");
  Serial.println("@help           - this help message.");
  Serial.println("<text>          - Display and scroll the text.");
  Serial.println("@ani1           - Display animation 1");
}

//Get width of a character
uint8_t getWidth(char decodechar) {
  // Lookup table for mapping characters to their width
  static const struct {
    char character;
    uint8_t width;
  } lookupTable[] = {
    {'A', 5}, {'B', 5}, {'C', 4}, {'D', 5}, {'E', 4},
    {'F', 4}, {'G', 5}, {'H', 5}, {'I', 3}, {'J', 4},
    {'K', 5}, {'L', 4}, {'M', 5}, {'N', 5}, {'O', 5},
    {'P', 5}, {'Q', 5}, {'R', 5}, {'S', 5}, {'T', 5},
    {'U', 5}, {'V', 5}, {'W', 5}, {'X', 5}, {'Y', 5},
    {'Z', 5}, 
    {'a', 5}, {'b', 5}, {'c', 4}, {'d', 5}, {'e', 4},
    {'f', 4}, {'g', 5}, {'h', 5}, {'i', 3}, {'j', 4},
    {'k', 5}, {'l', 4}, {'m', 5}, {'n', 5}, {'o', 5},
    {'p', 5}, {'q', 5}, {'r', 5}, {'s', 5}, {'t', 5},
    {'u', 5}, {'v', 5}, {'w', 5}, {'x', 5}, {'y', 5},
    {'z', 5},
    {'1', 4}, {'2', 5}, {'3', 5}, {'4', 5},
    {'5', 5}, {'6', 5}, {'7', 5}, {'8', 5}, {'9', 5},
    {'0', 5}, 
    {'.', 2}, {'!', 2}, {' ', 5}, {':', 2}, //2 weil Satzzeichen noch Space dahinter
    {'+', 3}, {'_', 5}, {'-', 3} // Add other symbols as needed
  };

  const size_t lookupTableSize = sizeof(lookupTable) / sizeof(lookupTable[0]);  // Number of entries in the lookup table

  // Search the table for the matching character
  for (size_t i = 0; i < lookupTableSize; i++) {
    if (lookupTable[i].character == decodechar) {
      return lookupTable[i].width;
    }
  }
  return 5;  // If character not found, return 5 (default width)
}

// ani1 function to display the animation
void ani1() {
  Serial.println("Displaying animation 1...");
  while(Serial.available()==false){
    // Add your animation code here  
  }
  // Once the animation is done, resume scrolling with the last text
  scrollingActive = true;
  if (lastText.length() > 0) {
    scrollText(lastText.c_str(), 0, scrollSpeed);
  }
}