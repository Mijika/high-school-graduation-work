#include "Sensor.h"

void Sensor::Sensor(int rate) { //Robot 클래스 초기화
    _hardness = "0";      //경도값
    _latitude = "0";      //위도값
    _altitud_gps = "0";   //gps고도값
    _altitud = "0";       //고도값
    _temperature = "0";   //온도값

    HardwareSerial SerialGPS(2);
    SerialGPS.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
    _SerialGPS = SerialGPS

    Serial.println("센서들 초기화 중....");
    _uart_gps.begin(BAUD_RATE);
    if(!bmp.begin(BMP085_ULTRAHIGHRES)) {
        Serial.println("BMP180 센서를 찾을 수 없습니다. 연결을 확인해 주세요!");
        return
    }
    if()

    Serial.println("센서들 초기화 완료....");
}

void Sensor::sening() { //sening 해서 내부 필드에 값 저장
    Serial.println("센싱중... ");
    delay(300);
    hardness = SensingGps_hardness();
    latitude = SensingGps_latitude();
    altitud_gps = SensingGps_altitud_gps();
    altitud = Sensing_altitude_altitude();
    temperature = Sensing_altitude_temperature();
    Serial.println("센싱 완료... ");
}

String Sensor::SensingGps_hardness() {  //gps 경도값 센싱
    /*    gps 경도값 가져오기
       return : (String)경도값
       // float 형의 값을 string 형으로 변환에서 리턴
    */
    float hardness, latitude; // 위도, 경도값을 전달할 변수

    if(_uart_gps.available()) {  //버퍼에 데이터가 있는지 확인
        int c = _uart_gps.read(); //버퍼에 들어가 있는 값을 c에 저장
        gps.encode(c); // gps 레퍼런스에 gps값 삽입
    }
    else { //없을 경우 오류 메세지 리턴
        return "gps 수신 오류";
    }

    gps.f_get_position(&hardness, &latitude); //위도, 경도갑을 변수에 삽입

    return String.valueOf(hardness); //경도값을 string 형으로 형 변환 하여 리턴
}

String Sensor::SensingGps_latitude() { //gps 위도값 센싱
    /*    gps 위도값 가져오기
       return : (String)위도값
       // float 형의 값을 string 형으로 변환에서 리턴
    */
    float hardness, latitude; // 위도, 경도값을 전달할 변수

    if(_uart_gps.available()) {  //버퍼에 데이터가 있는지 확인
        int c = _uart_gps.read(); //버퍼에 들어가 있는 값을 c에 저장
        gps.encode(c); // gps 레퍼런스에 gps값 삽입
    }
    else { //없을 경우 오류 메세지 리턴
        return "gps 수신 오류";
    }

    gps.f_get_position(&hardness, &latitude); //위도, 경도갑을 변수에 삽입

    return String.valueOf(latitude); //위도값을 string 형으로 형 변환 하여 리턴
}
String Sensor::SensingGps_altitud() {
    /*    gps 고도값 가져오기
       return : (String)고도값
       // float 형의 값을 string 형으로 변환에서 리턴
    */
    if(_uart_gps.available()) {  //버퍼에 데이터가 있는지 확인
        int c = _uart_gps.read(); //버퍼에 들어가 있는 값을 c에 저장
        gps.encode(c); // gps 레퍼런스에 gps값 삽입
    }
    else { //없을 경우 오류 메세지 리턴
        return "gps 수신 오류";
    }

    return String.valueOf(gps.f_altitude()); // gps 고도값을 string 형으로 형 변환 하여 리턴
}
String Sensor::Sensing_altitude_altitude() { //고도 센서에서 고도값 센싱
    /*  고도 센서에서 고도값 가져오기
        //기상청에서 우리나라 해면 기압 확인해서 코드에 반영한다.
            -이유: 고도센서에서 설정한 디폴트 값이 우리 나라의 해면 기압이 아니라서 오차 있음
        return : (String)고도값
        // float 형의 값을 string 형으로 변환에서 리턴
    */
    return String.valueOf(bmp.readAltitude(100560));
}
String Sensor::Sensing_altitude_temperature() { //고도 센서에서 온도값 센싱
    /*  고도 센서에서 온도값 가져오기
        return : (String)온도값
        // float 형의 값을 string 형으로 변환에서 리턴
    */
     return String.valueOf(bmp.readTemperature());
}

String Sensor::get_gps_hardness() { //gps 경도값 가져오기
    return _hardness;
}
String Sensor::get_gps_latitude() { //gps 위도값 가져오기
    return _latitude;
}
String Sensor::get_gps_altitud_gps() { //gps고도값 가져오기
    return _altitud_gps;
}
String Sensor::getAltitude_altitude() { //고도 센서에서 고도값 가져오기
    return _altitud;
}
String Sensor::getAltitude_temperature() { //고도 센서에서 온도값 가져오기
    return _temperature;
}
