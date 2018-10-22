# rpi-simple-iptv

Extremely simple IPTV solution for your grandparents!


## Concept

```
   .-------------------.
   |                   | 
+-----+  +----------+  |   +--------------------+
| Num |  | RPi  USB [--    |                    |
| pad |  |     HDMI [------|         TV         |
+-----+  |      ETH [--.   |                    |
         +----------+  |   +---------++---------+
                       |          ___||___
+-------------------+  |
|    IPTV server    |--
+-------------------+
```


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

