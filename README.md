# rpi-simple-iptv

Extremely simple IPTV solution for your grandparents!


## Concept

```
   .-----------------------------.
   |                             | 
+---------------+  +----------+  |   +--------------------+
| Potentiometer |  | RPi  USB [--    |                    |
| / remote      |  |     HDMI [------|         TV         |
+---------------+  |     WIFI [--.   |                    |
                   +----------+  |   +---------++---------+
                                 |          ___||___
+-------------------+            |
|    IPTV server    |------------
+-------------------+
```

- Raspberry pi zero with TVHAT sends chanels over wifi to raspberry pi in tv
- channels are selected by using a potentiometer or remote


possably usefull information:

https://www.instructables.com/id/Rotary-Knob-Alternative-TV-Remote/
https://thepihut.com/blogs/raspberry-pi-tutorials/how-to-stream-digital-tv-with-the-raspberry-pi-tv-hat#Accessing%20Tvheadend
https://www.raspberrypi.org/app/uploads/2018/10/Getting-started-with-the-Raspberry-Pi-TV-HAT.pdf

## Pre-requisites

Player dependencies:

* `bash` - 4.3.46
* `coreutils` - 8.25
* `findutils` - 4.6.0
* `grep` - 2.25
* `sed` - 4.2.2
* `curl` - 7.50.1
* `wget` - 1.18 (replacement for `curl`)
* `python` - 3.5.2
    * `python-evdev` - 0.6.1
* `omxplayer` - [popcornmix/omxplayer](https://github.com/popcornmix/omxplayer)

Server dependencies (optional):

* `aceproxy` - [AndreyPavlenko/aceproxy](https://github.com/AndreyPavlenko/aceproxy)

_Note: Version numbers are just FYI._

https://www.raspberrypi.org/documentation/raspbian/applications/omxplayer.md

## Setup

Options for making an IPTV playlist:

* Setup an `aceproxy` server, which can make an M3U with a ton of free channels;
* Make your own (annotated) M3U playlist.

This software expects the `tvg-name` annotation in playlist, which looks like this:

```
#EXTINF:-1 tvg-name="Foobar_TV",Foobar TV
```

Copy `config.conf.example` to `config.conf`, and configure everything to your liking.

When it's all done, start with `bash launch.sh`.

