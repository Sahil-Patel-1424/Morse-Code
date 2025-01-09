// initialize variables
int dot = 100;
int dash = dot * 3;
int blink_space = dot;
int character_space = dot * 5;
int word_space = dot * 7;
int pin_number = 13;

// an array of letters in morse code
char* letters[] = {
  ".-", "-...", "-.-.", "-..",  // A-D
  ".", "..-.", "--.", "....",   // E-H
  "..", ".---", "-.-", ".-..",  // I-L
  "--", "-.", "---", ".--.",    // M-P
  "--.-", ".-.", "...", "-",    // Q-T
  "..-", "...-", ".--", "-..-", // U-X
  "-.--", "--.."                // Y-Z
};

// an array of numbers in morse code
char* numbers[] = {
  ".----", "..---", "...--", "....-"  // 1-4
  ".....", "-....", "--...", "---.."  // 5-8
  "----.", "-----"                    // 9-0
};

// morse dot function
void morse_dot() {
  // turn pin on
  digitalWrite(pin_number, HIGH);

  // wait for 0.05 seconds
  delay(dot);

  // turn pin off
  digitalWrite(pin_number, LOW);
}

// morse dash function
void morse_dash() {
  // turn pin on
  digitalWrite(pin_number, HIGH);

  // wait for 0.15 seconds
  delay(dash);

  // turn pin off
  digitalWrite(pin_number, LOW);
}

// function that blinks character in morse code
void blink_morse(String character) {
  // go through the character
  for (int i = 0; i < character.length(); i++) {
    // if the current element is a dot
    if (character[i] == '.') {
      morse_dot();
    }

    // if the current element is a dash
    else if (character[i] == '-') {
      morse_dash();
    }

    // pause between dots and dashes
    delay(blink_space);
  }
}

// function that converts string to morse code
void text_to_morse(String text) {
  // convert all characters in string to upper case
  text.toUpperCase();

  // go through each character in the string
  for (int i = 0; i < text.length(); i++) {
    // get the character at current index
    char character = text[i];

    // if the character is a space
    if (character == ' ') {
      // pause between words
      delay(word_space);
    }

    // if the character is not a space
    else if (character != ' ') {
      // if the character is a letter
      if (isAlpha(character)) {
        // blink the letter
        blink_morse(letters[character - 'A']);
      }
      
      // if the character is a number
      if (isDigit(character)) {
        // blink the number
        blink_morse(numbers[character - '1']);
      }

      // pause between characters
      delay(character_space);
    }
  }
}

void setup() {
  // put your setup code here, to run once:

  // set pin 13 as an output signal
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // wait for 1 second at the start of program
  delay(1000);

  // create string and translate it to morse code
  String message = "SOS 123";
  text_to_morse(message);

  // wait for 1 second after program reached the end
  delay(1000);
}
