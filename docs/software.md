# Software Design

## Overview

本CanSatはESP32を用いて各種センサのデータ取得、
記録および表示を行う。

対象センサ

- BMP280（気圧）
- AHT20（温湿度）
- MPU6050（加速度・角速度）
- GPS（NEO-M8N）

取得データはCSV形式で保存する。

## Modules

### main.cpp
システム全体の制御

### sensor.cpp
BMP280
AHT20
MPU6050

の管理

### gps.cpp
GPSデータ取得

### display.cpp
OLED表示

### logger.cpp
CSV保存

## Log Format

TIME,LAT,LON,TEMP,HUM,PRES,AX,AY,AZ

例

12:00:00,
35.12345,
137.12345,
25.3,
60.2,
1012.5,
0.02,
0.01,
9.80