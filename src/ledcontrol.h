class LEDControl{
public:
    LEDControl(int ledChannel, int ledPin, int frequency, int resolution);
    void setBrightness(int brightness);
    void setFrequency(int frequency);
    void setup();
    void loop();
private:
    int ledChannel_;
    int ledPin_;
    int ledFrequency_;
    int ledResolution_;
};

