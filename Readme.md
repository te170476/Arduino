# Arduino
## proXX
IoT技術の授業の課題の回答としてのコード

## libraries/Pro - Arduino original library
授業で提示された課題用に書いたライブラリ

### Pro.h
[example](https://github.com/tcc170476/Arduino/blob/master/pro11/pro11.ino)
```
int leds[] = {5, 6, 7};
void setup() {
  pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(leds, HIGH);
}

```

### Pulser.h
```
int switchPin = 11;
Pulser pulser(switchPin);
void setup() {
  PulseState state = pulser.pulse();
  /* PulseState
   *   OFF
   *  ,AlreadyPulsed
   *  ,Pulse
   */
  if (state != PulseState::Pulse) return;
  // ここからパルス入力時の処理を記述
}
```

### Toggler.h
[example](https://github.com/tcc170476/Arduino/blob/master/pro14/pro14.ino)
```
int ledPin    = 5;
int switchPin = 11;
Toggler toggler(switchPin);
void loop() {
  boolean switchState = toggler.toggle();
  /* switchState
   *  true  (== HIGH)
   *  false (== LOW )
   */
}
```