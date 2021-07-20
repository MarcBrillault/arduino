# Purpose

Having a little game of blind test.

# Equipment

## Host box

- 1 USB port to read songs
- 4 USB ports to connect player boxes
- 4 Led lights to identify/check players
- 1 screen to see the song's name (LCD should do)
- 3 buttons :
  - Play
  - Correct answer
  - Incorrect answer

## Player boxes

- 1 USB port to connect to the main box
- 1 big colored 2-digit display on the back for the score
- 1 small colored 2-digit display on the front for the score
- 1 little colored 1-digit display on the front for the player ID
- 1 big mushroom button on top
- 1 light

# Game scenario

- Host connects an USB key to their box
  - Only mp3 files at the root of the key can be used
  - Alternatively, a mp3 folder can be created on the host's pi/arduino
- Players connect their boxes to the host box via USB
  - Their boxes show 0 in the smallest display
  - Their boxes show 0 in the two scores display
- Players activate their boxes by pressing the button
  - Button light turns on
  - On the host, an ID (1-4) is given to the player
  - On the host, the corresponding led activates and stays on
  - On the player's box, the ID display updates with the corresponding ID
- When all player boxes are activated, the host presses their "play" button
  - We enter the "unlock" state:
    - All the leds on the host box goes off
    - All the players buttons' light goes off
  - A randomly selected song starts to play
- Whenever any of the players presses their button :
  - We enter the "lock" state:
    - The music stops
    - Their light goes on
    - Other players input is ignored
    - The player ID goes on on the host's box
- If the host presses "Correct answer":
  - Corresponding player's score displays goes up by 1
- If the host presses "Incorrect answer":
  - Corresponding player's score is unchanged
- The host presses "play":
  - Enter the "unlock" state
  - If last press was an correct answer, a new random song is chosen (Excepted for the previously listened ones)
  - If last press was an incorrect answer, the song goes on where it was stopped
