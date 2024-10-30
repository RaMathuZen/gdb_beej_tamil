# GDB க்கான பீஜின் விரைவான வழிகாட்டி (Beej's Quick Guide to GDB)
*வெளியீடு 2 (2009 ஜூன் 14)*

இது குனு பிழைநீக்கி (GNU Debugger) பற்றிய மிகவும் விரைவான மற்றும் சுருக்கமான வழிகாட்டியாகும். 

குனு பிழைநீக்கி (GNU Debugger) ஒரு முனையத்தில்(terminal) கட்டளை வரியிலிருந்தே(command line) பெரும்பாலானநேரங்கள் பயன்படுத்தப்படுகிறது (IDE யை தாண்டி), அவ்வாறு பயன்படுத்த விரும்பினால் இந்த பயிற்சி உங்களுக்கானது!

மீண்டும் கூறுகிறேன், இது தொடக்க வழிகாட்டி மட்டுமே. இந்த சில பத்திகளில் எழுதப்பட்டதை விட பிழைத்திருத்தி என்ன செய்கிறது என்பதைப் பற்றி அறிய அதிகம் உள்ளன. அதற்கு உங்கள் gdb யின் **man pages** யையோ அல்லது வேறு வலைப்பூக்களையோ 
பாருங்கள்.

மேலும் பல தகவலுக்கு கீழே பட்டியலிடப்பட்டுள்ளதை பார்க்கவும்.

இந்த வழிகாட்டியை (Tutorial) வரிசையில் படிக்க வேண்டும். (misc பிரிவிற்க்கு பொருந்தாது).

## வேண்டுகோள்

இம்மொழிபெயர்ப்பில் ஏதேனும் பிழைகள் இருப்பின் அல்லது உங்கள் கருத்துக்களையோ இந்த மின்னஞ்சல் முகவரிக்கு (1729.annamal.ai@gmail.com) தெரிவிக்கவும்.

## பொருளடக்கம்

- [பிழைத்திருத்தியைப் பயன்படுத்த தொகுத்தல் (Compiling to use a Debugger)] (#compiling)
- [மேலும் தகவலிற்க்கு] (#more)
- [உரிமம்] (#license)
- [பிரேக் பாயிண்ட்ஸ் (Breakpoints)] (#breakpoints)
- [அடியெடுத்து வைத்தல் (Stepping Around)] (#stepping)
- [மாறிகளை ஆராய்தல் (Examining Variables)] (#exvars)
- [மற்ற விஷயங்கள் (Misc Stuff)] (#misc)
 - [ஸ்டாக்கை கையாளுதல் (Stack Manipulation)] (#stackman)
 - [கூடுதல் படி முறைகள்(Additional Stepping Methods)] (#morestep)
 - [குறியீட்டின் தன்னிச்சையான பகுதிக்கு குதித்தல் (Jumping to Arbitrary Section of Code] (#jump)
 - [இயக்க நேரத்தில் மாறிகள் மற்றும் மதிப்புகளை மாற்றுதல் (Changing Variables and Values at Runtime) ] (#varmod)
 - [வன்பொருள் கண்காணிப்பு புள்ளிகள் (Hardware Watchpoints)] (#hardwatch)
 - [இயங்கும் செயல்முறையுடன் இணைக்கவும் (Attach a running process)] (#attach)
 - [பிரேத பரிசோதனை பகுப்பாய்விற்கு கோர்டம்ப்களைப் பயன்படுத்துதல் (Using Coredumps for Postmortem Analysis)] (#coredump)
 - [சாளர செயல்பாடுகள் (Window Functions)] (#window)
 - [காட்சி பதிவேடுகள் (Display Registers) மற்றும் அசெம்ப்ளி (Assembly)] (#regasm)
 - [ஒரு முன்-அமைப்பு எழுதுதல் (Writing a Front-End)] (#frontend)
- [விரைவான குறிப்புத்தாள் (Quick Reference Cheat Sheet)] (#QREF)

[]{#compiling}

## தொகுத்தல் (Compiling) {#compiling .pbb}

உங்கள் நிறலை குறியீட்டு பிழைத்திருத்த தகவலுடன்(Symbolic Debugging Information) தொகுக்க உங்கள் தொகுப்பாளரிடம்(compiler) சொல்ல வேண்டும். 

இங்கே **gcc** உடன் இதை எப்படி செய்வது என்று காண்க (-ஜி (-g) சுவிட்சுடன்)

``` screen
$ gcc -g hello.c -o hello

$ g++ -g hello.cpp -o hello
```

நீங்கள் அதைச் செய்தவுடன், நீங்கள் நிரல் பட்டியல்களைக்(program listings) காண முடியும்.

[]{#more}

## மேலும் தகவலிற்க்கு (More Information)

[அதிகாரப்பூர்வ ஜி.டி.பி.ஆவணம்(GDB Documentation)](http://www.gnu.org/software/gdb/documentation/) 

மேலும், ஒரு நல்ல குனு ஜி.டி.பி front-end க்கு டி.டி.டி([DatadisplayDebugger](http://www.gnu.org/software/ddd/)]) யை பயன்படுத்தலாம்.

[]{#license}

## உரிமம்

[![Creative Commons
License](88x31.png){style="border-width:0;float:right;padding-left:20px;"}](http://creativecommons.org/licenses/by-nc-nd/3.0/us/){rel="license"
target="_blank"}

[Beej\'s Quick Guide to GDB]{xmlns:dc="http://purl.org/dc/elements/1.1/"
href="http://purl.org/dc/dcmitype/Text" property="dc:title"
rel="dc:type"} by [Brian \"Beej Jorgensen\"
Hall](http://beej.us/guide/bggdb/){xmlns:cc="http://creativecommons.org/ns#"
property="cc:attributionName" rel="cc:attributionURL"} is licensed under
a [Creative Commons Attribution-Noncommercial-No Derivative Works 3.0
United States
License](http://creativecommons.org/licenses/by-nc-nd/3.0/us/){rel="license"
target="_blank"}.

[]{#starting}

## பிழைத்திருத்தியைத் தொடங்குதல் (Starting the Debugger) {#starting-the-debugger .pbb}

முதலில் முதற்கட்ட விஷயங்கள்: நீங்கள் எந்த **gdb** தூண்டியிலும்(prompt) **help** கட்டளையை உள்ளிட்டு மேலும் தகவலை பெறலாம். மேலும், பிழைத்திருத்தியிலிருந்து வெளியேற நீங்கள் **quit** ஐ உள்ளிடலாம்.
இறுதியாக, **RETURN** ஐ அழுத்தினால் கடைசியாக உள்ளிடப்பட்ட கட்டளை மீண்டும் உள்ளீடாகும்.

இப்போது அதை பயன் படுத்தலாம் வாருங்கள்!

பிழைத்திருத்தியைத் தொடங்க பல வழிகள் உள்ளன (எ.கா. நீங்கள் IDE பயன்படுத்தினால் நீங்கள் அதை ஒரு குறிப்பிட்ட பயன்முறையில் தொடங்கலாம்). ஆனால் நான் இங்கே குறிப்பிடுவது: வெண்ணிலா கன்சோல்(console) பயன்முறை மற்றும் கர்சஸ்(curses) 
GUI முறை. GUI சிறப்பாக உள்ளது, ஆனால் எளிமையான ஒன்றை விரைவாகப் பார்ப்போம்.

பிழைத்திருத்தத்தில் **hello** என்ற நிரலைத் தொடங்கவும்:

``` திரை
$ gdb hello
GNU gdb 6.8
Copyright (C) 2008 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i486-slackware-linux"...
(gdb) run
Starting program: /home/beej/hello 
Hello, world!

Program exited normally.
(gdb) 
```

கடைசி வரியானது **gdb** ப்ராம்ட்(prompt) ஆகும், நீங்கள் என்ன சொல்ல போகிறீர்கள் என்பதை செய்ய காத்திருக்கிறது. நிரலை இயக்க **r** அல்லது **run** என தட்டச்சு செய்யவும். (**gdb** உங்களை கட்டளைகள் தெளிவற்றதாக மாறும் வரை 
அவற்றைச் சுருக்கவும் அனுமதிக்கிறது.)

**பரிந்துரைக்கப்பட்ட GUI பயன்முறையில் தொடங்க**, **gdb -tui** உடன் பிழைத்திருத்தியை தொடங்கவும். (பல எடுத்துக்காட்டுகளுக்கு, கீழே, நான் **gdb**\'s dumb டெர்மினல் பயன்முறையின் வெளியீடுகளை காட்டுகிறேன் , ஆனால் நிஜ வாழ்க்கையில் நான் TUI பயன்முறையைப் பயன்படுத்துகிறேன் பிரத்தியேகமாக.)

தோராயமாக நீங்கள் பார்ப்பதற்கான ஸ்கிரீன் ஷாட் இங்கே:

![](hellotui.png){.figureimg border="0"}

அனைத்து சாதாரண **gdb** கட்டளைகளும் GUI பயன்முறையிலையும் வேலை செய்யும், மேலும் கூடுதலாக அம்பு விசைகள் மற்றும் pgup/pgdown விசைகள் மூல சாளரத்தை(window) உருட்டும் (எப்போது இது கவனம்(focus) செலுத்தும் போது, அது இயல்பாகவே    செய்கிறது). மேலும், நீங்கள் எந்த கோப்பையையோ அல்லது செயல்பாடையோ **list** கட்டளையை (வாதமாக இருப்பிடத்துடன் (list as an arguement with its location)) வழங்குவதன் மூலம் மூல சாளரத்தில் காட்டப்படும்.

எடுத்துக்காட்டாக, **list hello.c:5** வரி 5 இல் `hello.c`{.filename} கோப்பைக் கொண்டு வரும். (பார்க்க \"[பிரேக் பாயிண்ட்ஸ்](#பிரேக் பாயிண்ட்ஸ்)\", கீழே, மாதிரி இருப்பிடங்களுக்கு---அதே பிரேக் பாயிண்ட்களுடன் வேலை செய்யும் இடங்கள் 
**list உடனும் வேலை செய்யும்**.) ​​ஒரு சின்ன குறிப்பாக, **list** டம்ப்(Dumb) டெர்மினல் பயன்முறையிலும் செயல்படுகிறது.

இப்போது, ​​நாம் command line-ல் executable-ன் பெயரை அனுப்பியதைக் கவனியுங்கள். உங்களிடம் உள்ள மற்றொரு வழி, வேறு எதுவும் இல்லாமல் **gdb** ஐத் தொடங்குவது, பின்  கட்டளை வரியில், **file hello** கட்டளையை கொடுக்கவும். இது
executable \"hello\" வை ஏற்றும்(load).

கட்டளை வரி வாதங்கள்(command line arguements)! உங்கள் நிரலின் argv-ற்க்கு எதையேனும் கொடுக்க வேண்டுமா ? அப்படியானால் அதை run/r கட்டளையின் வாதங்களாக கொடுக்கவும்.


``` screen
$ gdb hello
GNU gdb 6.8
Copyright (C) 2008 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i486-slackware-linux"...
(gdb) run arg1 arg2
Starting program: /home/beej/hello arg1 arg2
Hello, world!

Program exited normally.
(gdb)
```

மேலே, \"நிரலைத் தொடங்குதல்\" (Starting program) என்று எங்கு கூறுகிறது என்பதைக் கவனியுங்கள் அது \"arg1\" மற்றும் \"arg2\" \"ஹலோ\"க்கு அனுப்பப்படுவதை காட்டுகிறது.

## பிரேக் பாயிண்ட்ஸ் (Break Points) {#breakpoints .pbb}

நிரலை நேரடியாக இயக்க பிழைத்திருத்தியிலுருந்து தொடங்குவது மிகவும் பயனுள்ளது இல்லை --- நாம் செயல்படுத்துவதை நிறுத்திவிட்டு (அதாவது break செய்து), படிமுறையில் இறங்க வேண்டும் (step பண்ண வேண்டும்).

முதலில், **run** கட்டளையை செயல்படுத்துவதற்கு முன், நீங்கள் நிறுத்த விரும்பும் ஒரு இடத்தில் breakpoint-யை அமைக்க வேண்டும். நீங்கள் **break** அல்லது **b** பயன்படுத்தி, ஒரு இடத்தை குறிப்பிடவும், இது ஒரு செயல்பாட்டு பெயர், 
ஒரு வரியாக இருக்கலாம் எண், அல்லது ஒரு மூல கோப்பு மற்றும் வரி எண் ஆக இருக்கலாம்.

இடங்கள் என்பதற்கான உதாரணங்கள் இவை, இவை பல்வேறு கட்டளைகளால் பயன்படுத்தப்படுகின்றன **break** உட்பட:

 ---------------------------------------------------- -------------------------------
 **break main** `main()`{.function} செயல்பாட்டின் தொடக்கத்தில் உடைக்கவும்
 **break 5** தற்போதைய கோப்பின் 5வது வரியில் உடைக்கவும்
 **break hello.c:5** `hello.c`{.filename} இன் வரி 5ல் முறியவும்
 ---------------------------------------------------- -------------------------------

எனவே இந்தச் சோதனைக்கு, `main()`{.function}ல் breakpoint அமைத்து தொடங்குக, மற்றும்
நிரலை தொடங்குக:


``` screen
$ gdb hello
GNU gdb 6.8
Copyright (C) 2008 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i486-slackware-linux"...
(gdb) b main
Breakpoint 1 at 0x8048395: file hello.c, line 5.
(gdb) r
Starting program: /home/beej/hello 

Breakpoint 1, main () at hello.c:5
5		printf("Hello, world!\n");
(gdb)
```

நீங்கள் பார்ப்பது போல், நாம் `main`{.function} க்கு வந்துவிட்டோம் மற்றும் செயல்படுத்தல்(execution) நாம் அங்கு அமைத்த breakpoint ஆல் நிறுத்தப்பட்டது. நீங்கள் dumb ஆக  terminal mode யை பயன்படுத்தினால், **gdb** அடுத்து இயக்கும் 
வரியை அச்சிடும். நீங்கள் கூல் GUI பயன்முறையில் இயங்குகிறீர்கள் என்றால், அடுத்து அது செயல்படுத்தும் வரியை மூல சாளரத்தில் மிகுதியாக காட்டும்.

தற்போதைய முறிவு புள்ளிகளை (break points) பட்டியலிட, **info** கட்டளையைப் பயன்படுத்தவும்: அதாவது \"**info breakpoints**\" (அல்லது சுருக்கமாக \"**i b**\"):

``` screen
(gdb) b main
Breakpoint 1 at 0x8048395: file hello.c, line 5.
(gdb) i b
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x08048395 in main at hello.c:5
```

பிரேக் பாயின்ட்டை அழிக்க, பிரேக் பாயிண்டுடின் இடத்தை **clear** கட்டளையுடன் பயன்படுத்தவும். **delete** கட்டளை மூலம் எண் வாரியாக முறிவுப் புள்ளியை அழிக்கலாம்.

கூடுதலாக, நீங்கள் பிரேக் பாயிண்ட்களை **enable(இயக்கு)** or **disable(முடக்கு)** செய்யலாம் இந்த இரண்டு கட்டளைகளும் பிரேக்பாயிண்ட் எண்ணை ஒரு வாதமாக எடுத்துக்கொள்கின்றன, இடம்(location)  அல்ல! பிரேக் பாயின்ட்டின் இயக்கப்பட்ட/முடக்கப்பட்ட நிலையை கீழே தெரியும் பிரேக்பாயிண்ட் பட்டியலில் உள்ள \"Enb\" நெடுவரிசையில் காணலாம்.

``` screen
(gdb) i b
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x08048395 in main at hello.c:5
(gdb) disable 1
(gdb) i b
Num     Type           Disp Enb Address    What
1       breakpoint     keep n   0x08048395 in main at hello.c:5
(gdb) clear main
Deleted breakpoint 1 
(gdb) i b
No breakpoints or watchpoints.
```

[]{#ஸ்டெப்பிங்}

## அடியெடுத்து ஆராய்தல் (Stepping Around) {#ஸ்டெப்பிங்-அரவுண்ட் .pbb}

ஒரு breakpoint-ல் செயல்படுத்தல்(execution) நிறுத்தப்பட்டதும், பிழைத்திருத்தியை ஒரு சில விஷயங்களை செய்யச் சொல்லலாம். **next** கட்டளையுடன் (அல்லது **n**) தொடங்குவோம். இது தற்போதைய செயல்பாட்டின்(function) அடுத்த வரிக்கு கட்டளை 
உங்களை நகர்த்துகிறது (அல்லது நீங்கள் செயல்பாட்டின் முடிவில் இருந்து வெளியேறினால், செயல்பாட்டின் அழைப்பாளருக்குத் திரும்பும்.)  இங்கே ஒரு மாதிரி ஒட்டம்; (**gdb** *அடுத்த* வரியை \"(gdb)\" ப்ராம்ட்க்கு முன் அச்சிடுகிறது என்பதை நினைவில் 
கொள்ளுங்கள்!)  மேலும் `printf()`{.function} வரியில் **next** ஐ இயக்கும்போது, ​​நாம் வெளியீடு(output) தோன்றுவதைப் பார்க்கலாம்.

``` screen
(gdb) b main
Breakpoint 1 at 0x8048395: file hello.c, line 5.
(gdb) r
Starting program: /home/beej/hello 

Breakpoint 1, main () at hello.c:5
5		printf("Hello, world!\n");
(gdb) next
Hello, world!
7		return 0;
(gdb) next
8	}
(gdb) next
0xb7d6c6a5 in __libc_start_main () from /lib/libc.so.6
(gdb) next
Single stepping until exit from function __libc_start_main, 
which has no line number information.

Program exited normally.
(gdb) 
```

கடைசியில் (` __libc_start_main()`{.function} பற்றிய விசித்திரமான விஷயங்கள் காணப்படுகின்றன. அது உங்கள் `main()`{.function} செயல்பாடை மற்றொரு செயல்பாடு அழைகப்பதாக காட்டுகிறது!. இது பிழைத்திருத்தத்துடன் தொகுக்கப்படவில்லை,
ஆகையால் தகவலின் மூலத்தைப் பார்க்க முடியாது, எனினும் நாம் இன்னும் முன்னேறலாம் (Further Stepping) அதை நாம் செய்கிறோம் பின் நிரல் சாதாரணமாக வெளியேறும்.)

இப்போது, ​​**next** செயல்பாடு அழைப்புகளை (function calls) *steps over* செய்வதைக் கவனியுங்கள். இது செயல்பாடு அழைக்கப்படாது என்று அர்த்தம் இல்லை, **next** செயல்பாடு முடியும் வரை அதை இயக்கவும் என்று அர்த்தம், பின்னர் உங்களை 
தற்போதைய செயல்பாட்டில் உள்ள அடுத்த வரிக்குத் திருப்பும் .

உங்களிடம் ஒரு செயல்பாடு இருந்தால், உங்கள் நடப்பில் இருந்து *படியெடுக்க* விரும்புகிறீர்கள் மற்றும் அந்த செயல்பாட்டின் வரி-வரி-வரி மூலம் கண்டுபிடிக்க? **step** யை பயன்படுத்தவும் (அல்லது **s**). இது **next** போலவே செயல்படுகிறது 
step , செயல்பாடுகளில் படியெடுத்தல் தவிர.

நீங்கள் தொடர்ந்து ஒற்றை அடியெடுத்து வைப்பதில்(single stepping) சோர்வடைந்துவிட்டீர்கள் மற்றும் நிரலை மீண்டும் இயக்க விரும்புகிறீர்கள் என்று வைத்துக்கொள்வோம். அப்படியெனில் **continue(தொடரு)** (அல்லது **c**) கட்டளையைப் பயன்படுத்தவும்.

நிரல் இயங்கிக் கொண்டிருகிறது ஆனால் பிரேக் பாயின்ட்களை அமைக்க மறந்துவிட்டால் என்றால் என்ன செய்வது? நீங்கள் **CTRL-C** ஐ அழுத்தினால், அது எங்கு நடந்தாலும்(run) நிரலை நிறுத்தும் மற்றும் உங்களை \"(gdb)\" ப்ராம்ட்க்கு திருப்பி விடும். 
அந்த நேரத்தில், நீங்கள் எங்காவது ஒரு சரியான முறிவு புள்ளி அமைக்கலாம்  மற்றும் **continue** கொடுத்து  அந்த முறிவு புள்ளிக்கு செல்லலாம்.

ஒரு இறுதி குறுக்குவழி என்னவென்றால், **RETURN** என்பதை அழுத்தினால் கடைசி கட்டளையை மீண்டும் உள்ளிடப்படும்; இது **next** ஐ மீண்டும் மீண்டும் தட்டச்சு செய்வதை தவிர்க்கும்.

[]{#exvars}

## ஆய்வு மாறிகள் (Examining Variables) {#examining-variables .pbb}

உங்களிடம் சில மாறிகள் இருந்தால், காலப்போக்கில் ஆய்வு செய்ய விரும்புகிறீர்கள் என்றால் **run** செய்து, நீங்கள் அவற்றை **display** செய்யலாம் (ஆனால் மாறி தற்போது scope-ல் இருந்தால் மட்டுமே).
ஒவ்வொரு முறையும் நீங்கள் நிரலை **step** செய்யும் போது, ​​மாறியின் மதிப்பு காட்டப்படும் (அது scope-ல் இருந்தால் மட்டுமே).

(பின்வரும் வெளியீட்டில் வரிகளுக்கு இடையே உள்ள மூல நிரல் வெளியீடு தெளிவிற்க்காக காட்ட படவில்லை  --- இதை GUI பயன்முறையில் நீங்கள் பார்க்கலாம். நீங்கள் **run** செய்யும் போது, ​​மூலக் நிரலைச் சுற்றி தனிப்படுத்தி பட்டி துள்ளுவதைத்
(highlight bar bouncing)  நீங்கள் பார்க்கிறீர்கள் என்று கற்பனை செய்து பாருங்கள் :)


``` screen
(gdb) b main
Breakpoint 1 at 0x8048365: file hello.c, line 5.
(gdb) r
Starting program: /home/beej/hello 

Breakpoint 1, main () at hello.c:5
(gdb) disp i
1: i = -1207447872
(gdb) next
1: i = 1
(gdb) next
1: i = 1
(gdb) next
1: i = 2
(gdb) next
1: i = 2
(gdb) next
1: i = 4
(gdb) next
1: i = 4
(gdb) next
1: i = 4
(gdb) 
```

மேலே உள்ள \"i\"க்கு இடதுபுறத்தில் உள்ள எண், மாறியின் காட்சி எண்(display number of variable). இந்த எண்ணைப் பயன்படுத்தி மாறியை **undisplay** செய்யலாம். காட்சி எண்களை மறந்தால், அவற்றைப் பெற நீங்கள் **info display** என 
தட்டச்சு செய்யலாம்:

``` screen
(gdb) b main
Breakpoint 1 at 0x8048365: file hello.c, line 5.
(gdb) r
Starting program: /home/beej/hello 

Breakpoint 1, main () at hello.c:5
(gdb) display i
1: i = -1207447872
(gdb) info display
Auto-display expressions now in effect:
Num Enb Expression
1:   y  i
(gdb) undisplay 1
(gdb)
```

நீங்கள் ஒரு மாறியின் மதிப்பை ஒரு சில தடவை மட்டும் அறிய விரும்பினால், அதை **print** செய்யலாம். இங்கே \"i\" இன் மதிப்பு 40 என்பதைக் காண்கிறோம்:

``` screen
(gdb) print i
$1 = 40
(gdb)
```

(\"\$\" பின் உள்ள எண்ணுக்கு அர்த்தம் ஒன்று உள்ளது, ஆனால் அது ஆரம்பநிலையில் முக்கியமானது இல்லை).


நீங்கள் சிறப்பாகப் பயன்படுத்தக்கூடிய எளிதான **printf** கட்டளையும் உள்ளது, நீங்கள் உங்கள் வெளியீட்டை வடிவமைக்க(format) விரும்பினால்:

``` screen
(gdb) printf "%d\n", i
40
(gdb) printf "%08X\n", i
00000028
(gdb)
```
[]{#misc} []{#misc}

## இதர வழிமுறைகள் (Misc Stuff){#misc-stuff .pbb}

இது முந்தைய பிரிவுகளில் பொருந்தாத வழிமுறைகள், ஆனால் அது எங்கோ பட்டியலிட போதுமான வேடிக்கை கொண்டவை.

[]{#stackman}

### ஸ்டாக் கையாளுதல் (Stack Manipulation)

**backtrace** (அல்லது **bt**) கட்டளை தற்போதைய செயல்பாட்டுடைய கால் ஸ்டேக்கை (Call Stack) காண்பிக்கும், மேலே தற்போதைய செயல்பாடையும் மற்றும் அழைப்பாளர்களை (callers) அதன் கீழே ஆர்டர் செய்யும்:

``` screen
(gdb) backtrace
#0  subsubfunction () at hello.c:5
#1  0x080483a7 in subfunction () at hello.c:10
#2  0x080483cf in main () at hello.c:16
(gdb)
```

இதை வைத்து நீங்கள் என்ன செய்யலாம் என்பது பற்றிய கூடுதல் தகவலுக்கு **help stack** என தட்டச்சு செய்யவும்.

[]{#morestep}

### கூடுதல் படிமுறைகள் (Additional Stepping Methods)

தற்போதைய செயல்பாட்டிலிருந்து வெளியேறி, அழைப்பு செயல்பாட்டிற்கு திரும்ப, **finish** கட்டளையைப் பயன்படுத்தவும்.

ஒற்றை அசெம்பிளி instruction ஆக அடியெடுக்க, **stepi** கட்டளையைப் பயன்படுத்தவும்.

ஒரு குறிப்பிட்ட இடத்திற்குத் தொடர, **advance** கட்டளையை பயன்படுத்தி மேலே உள்ள "பிரேக் பாயிண்ட்ஸ்" பிரிவில் காட்டப்பட்டுள்ளதைப் போன்ற ஒரு இடத்தைக் குறிப்பிடுவும். நடப்பு இடத்திலிருந்து `subsubfunction()` எனப்படும் செயல்பாடு வரை 
முன்னேற ஒரு எடுத்துக்காட்டு இங்கே:

``` screen
Breakpoint 1, main () at hello.c:15
15		printf("Hello, world!\n");
(gdb) advance subsubfunction
Hello, world!
subsubfunction () at hello.c:5
5		printf("Deepest!\n");
(gdb) 
```

**advance** கட்டளை என்பது "இந்த தற்காலிக முறிவுக்குத் தொடரு" என்பதற்கான சுருக்கெழுத்து(shortcut) மட்டுமே.

[]{#jump}

### குறியீட்டின் தன்னிச்சையான பிரிவுக்குத் தாவுதல் (Jumping to arbitrary section of code)

**jump**(ஜம்ப்) கட்டளையானது, வாதமாகத்(arguement) தாவுவதற்கு ஒரு இடத்தை(location) எடுக்கும் தவிர, **continue** போலவே செயல்படுகிறது. (இடங்களைப் பற்றிய கூடுதல் தகவலுக்கு, மேலே உள்ள "பிரேக் பாயிண்ட்ஸ்" பகுதியைப் பார்க்கவும்.)

நீங்கள் ஜம்ப் இலக்கில் நிறுத்த வேண்டும் என்றால், முதலில் அங்கு ஒரு முறிவுபுள்ளியை(breakpoint) அமைக்கவும்.

[]{#varmod}

### இயக்க நேரத்தில் மாறிகள் மற்றும் மதிப்புகளை மாற்றுதல் (Changing Variables and Values at runtime)

ஒரு வெளிப்பாட்டுடன்(expression) **set variable** கட்டளையைப் பயன்படுத்தி, இயங்கும் போது(at runtime) மாறியின் மதிப்பை மாற்ற உங்களை அனுமதிக்கிறது. அடைப்புக் குறியிடப்பட்ட வெளிப்பாட்டுடன்(expression with parantheses) தொகுப்பைப் 
பயன்படுத்துவதன் மூலமும் நீங்கள் இதை சுருக்கமாக மாற்றலாம்:

``` screen
Breakpoint 1, main () at hello.c:15
15		int i = 10;
(gdb) print i
$1 = -1208234304
(gdb) set (i = 20)
(gdb) print i
$2 = 20
(gdb) set variable i = 40
(gdb) print i
$3 = 40
(gdb) 
```

இது, ஜம்ப்(jump) கட்டளையுடன் சேர்ந்து, நிரலை மறுதொடக்கம் செய்யாமல் குறியீட்டின் பிரிவுகளை(sections of code) மீண்டும் run(இயக்க) செய்ய உதவும்.

[]{#hardwatch}

### வன்பொருள் கண்காணிப்பு புள்ளிகள் (Hardware Watchpoints)

ஹார்டுவேர் வாட்ச் பாயிண்ட்ஸ் என்பது எக்ஸ்பிரஷன் மாறும்போதெல்லாம் தூண்டும் சிறப்பு பிரேக் பாயிண்டுகள். ஒரு மாறி மாறும் போது (எழுதப்பட்டது) அதை நீங்கள் அடிக்கடி தெரிந்து கொள்ள விரும்புகிறீர்கள் என்றால், அதற்காக நீங்கள் **watch** (வாட்ச்) 
கட்டளையைப் பயன்படுத்தலாம்:

``` screen
Breakpoint 1, main () at hello.c:5
5		int i = 1;
(gdb) watch i
Hardware watchpoint 2: i
(gdb) continue
Continuing.
Hardware watchpoint 2: i

Old value = -1208361280
New value = 2
main () at hello.c:7
7		while (i < 100) {
(gdb) continue
Continuing.
Hardware watchpoint 2: i

Old value = 2
New value = 3
main () at hello.c:7
7		while (i < 100) {
(gdb)
```
வாட்ச் ஒரு வெளிப்பாட்டை(expression) ஒரு வாதமாக எடுத்துக்கொள்கிறது என்பதை நினைவில் கொள்ளவும், எனவே நீங்கள் அதில் ஒரு மாறி பெயரை வைக்கலாம் அல்லது *(p+5) அல்லது a[15] போன்ற சிக்கலான ஒன்றை வைக்கலாம். i > 10 போன்ற 
நிபந்தனை வெளிப்பாடுகளுடன் கூட முயற்சித்தேன், ஆனால் கலவையான முடிவுகள் கிடைத்துள்ளன.

**info break** அல்லது **info watch** மூலம் வாட்ச் பாயின்ட்களின் பட்டியலைப் பெறலாம், மேலும் அவற்றை **delete**(நீக்கு) கட்டளை மூலம் எண்ணை வைத்து நீக்கலாம்.

இறுதியாக, **rwatch** ஐப் பயன்படுத்தி ஒரு மாறி படிக்கப்படும்போதும் மற்றும் ​​அது எப்போது படிக்கப்படுகிறது அல்லது எழுதப்படுகிறது என்பதைக் கண்டறிய **awatch** ஐப் பயன்படுத்தி தெரிந்து கொள்ளலாம்.

[]{#attach}

### இயங்கும் செயல்முறையுடன் இணைக்கவும் (Attach to a running process)

உங்கள் நிரல் ஏற்கனவே இயங்கி கொண்டிருந்தால், அதை நிறுத்தி பிழைத்திருத்தம் செய்ய விரும்பினால், முதலில் உங்களுக்கு செயல்முறை ஐடி (PID) தேவைப்படும், அது ஒரு எண்ணாக இருக்கும். (அதை Unix இன் ps கட்டளையிலிருந்து பெறவும்.) பின்னர் 
நீங்கள் இயங்கும் நிரலை இணைக்க (மற்றும் உடைக்க(break)) PID உடன் **attach**(இணைக்கும்) கட்டளையைப் பயன்படுத்துவீர்கள்.

இதற்கு, நீங்கள் எந்த வாதங்களும் இல்லாமல் gdb ஐத் தொடங்கலாம்.

பின்வரும் முழுமையான ஓட்டத்தில்(complete run), நீங்கள் சில விஷயங்களைக் கவனிப்பீர்கள். முதலில் நான் இயங்கும் செயல்முறையை இணைக்கிறேன், அது __nanosleep_nocancel() எனப்படும் சில செயல்பாட்டில் உள்ளது என்று கூறுகிறது, இது எனது 
குறியீட்டில் நான் sleep() என்று அழைத்ததில் ஆச்சரியமில்லை. உண்மையில், பேக்ட்ரேஸைக் கேட்டால் இந்த அழைப்பு அடுக்கைக்(call stack) காட்டுகிறது. எனவே main() க்கு திரும்புவதற்கு இரண்டு முறை **finish** கட்டளையை சொல்கிறேன்.

``` screen
$ gdb
GNU gdb 6.8
Copyright (C) 2008 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i486-slackware-linux".
(gdb) attach 3490
Attaching to process 3490
Reading symbols from /home/beej/hello...done.
Reading symbols from /lib/libsafe.so.2...done.
Loaded symbols for /lib/libsafe.so.2
Reading symbols from /lib/libc.so.6...done.
Loaded symbols for /lib/libc.so.6
Reading symbols from /lib/libdl.so.2...done.
Loaded symbols for /lib/libdl.so.2
Reading symbols from /lib/ld-linux.so.2...done.
Loaded symbols for /lib/ld-linux.so.2
0xb7eab21b in __nanosleep_nocancel () from /lib/libc.so.6
(gdb) backtrace 
#0  0xb7eab21b in __nanosleep_nocancel () from /lib/libc.so.6
#1  0xb7eab05f in sleep () from /lib/libc.so.6
#2  0x080483ab in main () at hello.c:10
(gdb) finish
Run till exit from #0  0xb7eab21b in __nanosleep_nocancel ()
   from /lib/libc.so.6
0xb7eab05f in sleep () from /lib/libc.so.6
(gdb) finish
Run till exit from #0  0xb7eab05f in sleep () from /lib/libc.so.6
0x080483ab in main () at hello.c:10
10			sleep(1);
(gdb) list
5	{
6		int i = 1;
7	
8		while (i < 60) {
9			i++;
10			sleep(1);
11		}
12	
13		return 0;
14	}
(gdb) print i
$1 = 19
(gdb) quit
The program is running.  Quit anyway (and detach it)? (y or n) y
Detaching from program: /home/beej/hello, process 3490
```

நான் main() க்கு திரும்பும் போது, ​​நான் i இன் மதிப்பை அச்சிடுகிறேன், அது 19 ஆகும் - ஏனெனில் இந்த விஷயத்தில் நிரல் 19 வினாடிகளுக்கு இயங்குகிறது, மேலும் நான் ஒரு வினாடிக்கு ஒரு முறை i யின் மதிப்பு ஒன்று அதிகரிக்கிறேன்.

பிழைத்திருத்தத்திலிருந்து வெளியேறி, நிரலில் இருந்து பிரிந்துவிட்டவுடன், நிரல் சாதாரணமாக இயங்கும்.

இதை மேலே உள்ள **set variable** உடன் கலக்கும் போது, உங்களுக்கு கொஞ்சம் சக்தி கிடைத்துள்ளது!

[]{#coredump}

### போஸ்ட்மார்ட்டம் பகுப்பாய்விற்கு கோரடம்ப்களைப் பயன்படுத்துதல் (Using Coredumps for Postmortem Analysis)

நீங்கள் ஒரு நிரலை உருவாக்கி(build செய்து) இயக்குகிறீர்கள்(run) என்று வைத்துக்கொள்வோம், மேலும் அது சில காரணங்களுக்காக அல்லது இன்னொரு காரணத்திற்காக உங்கள் மீது மையத்தை (core dump) செலுத்துகிறது:

``` screen
$ cc -g -o foo foo.c
$ ./foo
Segmentation fault (core dumped)
```

இதன் பொருள் ஒரு கோர்(core) கோப்பு (விபத்து நேரத்திலிருந்து நினைவக ஸ்னாப்ஷாட்டுடன்(memory snapshot at the time of crash)) "கோர்"(core) என்ற பெயரில் உருவாக்கப்பட்டது. நீங்கள் ஒரு கோர் கோப்பைப் பெறவில்லை என்றால் (அதாவது, அது 
"segmentation fault" என்று மட்டுமே கூறுகிறது மற்றும் எந்த core கோப்பும் உருவாக்கப்படவில்லை), உங்கள் ulimit மிகக் குறைவாக அமைக்கப்படலாம்; உங்கள் ஷெல் வரியில் `ulimit -c unlimited` தட்டச்சு செய்ய முயற்சிக்கவும்.

கோர் கோப்பைக் குறிப்பிட -c விருப்பத்துடன்(option/flag) gdb ஐ இயக்கலாம்:

``` screen
gdb -tui -c core foo
```

மேலும், TUI பயன்முறையில் இருந்தால், நிரல் ஏன் வெளியேறியது ("signal 11, segmentation fault") என்பதைத் தெரிவிக்கும் தகவலின் திரையுடன் நீங்கள் வரவேற்கப்படுவீர்கள். (ஊமை முனைய(dumb terminal) பயன்முறையில், மீறும் வரி அச்சிடப்படுகிறது.)

இந்த எடுத்துக்காட்டில், சிக்கலை ஏற்படுத்தும் மாறியை நான் அச்சிடுகிறேன். உண்மையில் இது பூஜ்யமானது(NULL):

![](coredump.png){.figureimg border="0"

உங்களிடம் எல்லா மூலக் குறியீடும் இல்லாவிட்டாலும், நிரல் செயலிழந்த புள்ளியிலிருந்து (crash point) பின்னோக்கிப் பெறுவது(backtrace) பெரும்பாலும் பயனுள்ளதாக இருக்கும்.

[]{#window}

### சாளர செயல்பாடுகள் (Window Functions)

TUI பயன்முறையில், `info win` கட்டளையுடன் இருக்கும் சாளரங்களின் பட்டியலைப் பெறலாம். focus (ஃபோகஸ்) (அல்லது fs) கட்டளை மூலம் எந்த விண்டோவில் ஃபோகஸ் உள்ளது என்பதை நீங்கள் மாற்றலாம். focus ஒரு சாளரத்தின் பெயரை அல்லது 
"முந்தைய" அல்லது "அடுத்து" ஒரு வாதமாக எடுக்கிறது. சரியான சாளர பெயர்கள் "SRC" (மூல சாளரம்), "CMD" (கட்டளை சாளரம்), "REGS" (பதிவு சாளரம்) மற்றும் "ASM" (அசெம்பிளி சாளரம்). இந்த மற்ற சாளரங்களை எவ்வாறு பயன்படுத்துவது என்பதை 
அடுத்த பகுதியைப் பார்க்கவும்.

SRC சாளரத்தில் ஃபோகஸ் இருக்கும்போது, ​​அம்புக்குறி விசைகள் மூலக் குறியீட்டை நகர்த்தும், ஆனால் CMD சாளரத்தில் ஃபோகஸ் இருக்கும்போது, ​​அம்புக்குறி விசைகள் கட்டளை வரலாற்றில் முந்தைய மற்றும் அடுத்த கட்டளைகளைத் தேர்ந்தெடுக்கும். 
(பதிவுக்கு, SRC சாளரத்தை ஒற்றை வரிகள் மற்றும் ஒற்றை பக்கங்களை நகர்த்துவதற்கான கட்டளைகள் +, -, <, மற்றும் > ஆகும்.)

``` screen
(gdb) info win
        SRC     (36 lines)  <has focus>
        CMD     (18 lines)
(gdb) fs next
Focus set to CMD window.
(gdb) info win
        SRC     (36 lines)
        CMD     (18 lines)  <has focus>
(gdb) fs SRC
Focus set to SRC window.
(gdb)
```
(சாளரப் பெயர்கள் கேஸ் இன்-சென்சிட்டிவ் (case sensitive) ஆனவை.

winheight (அல்லது wh) கட்டளை ஒரு குறிப்பிட்ட சாளரத்தின் உயரத்தை அமைக்கிறது(sets), ஆனால் இது நன்றாக வேலை செய்வதில் எனக்கு துரதிர்ஷ்டம் ஏற்பட்டது.

[]{#regasm}

### காட்சி பதிவுகள் மற்றும் சட்டசபை (Display Registers and Assembly)

TUI பயன்முறையில், `layout` (தளவமைப்பு) கட்டளை நீங்கள் பார்க்கும் சாளரங்களைக் கட்டுப்படுத்துகிறது. கூடுதலாக, `tui reg` பதிவு சாளரத்தை கட்டுப்படுத்த அனுமதிக்கிறது, மேலும் அது ஏற்கனவே திறக்கப்படவில்லை என்றால் அதைத் திறக்கும்.

சில கட்டளைகள்:

------------------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
layout src          நிலையான தளவமைப்பு(standard layout) - மேலே மூல(source code), கீழே கட்டளை(command window) சாளரம்
layout asm          "src" தளவமைப்பைப் போலவே, மேலே ஒரு assembly சாளரம்(மூல நிரல் பதில்) தவிர
layout split        மூன்று சாளரங்கள்: மேல் மூலமும், நடுவில் அசெம்பிளியும், கீழே கட்டளையும்
layout reg          எதேனும் கடைசியாகத் திறக்கப்பட்ட மூல அல்லது அசெம்பிளி சாளரத்தின் மேல் பதிவு சாளரத்தைத் திறக்கிறது.
tui reg general     பொது பதிவேடுகளைக்(registers) காட்டு
tui reg float       மிதக்கும் புள்ளி(floating point) பதிவேடுகளைக் காட்டு
tui reg system      "system" பதிவேடுகளைக் காட்டு
tui reg next        பதிவேடுகளின் அடுத்த பக்கத்தைக் காட்டு - இது முக்கியமானது ஏனெனில் "பொது", "float" அல்லது "system" தொகுப்புகளில் இல்லாத பதிவேடுகளின் பக்கங்கள் இருக்கலாம்
------------------ --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


உங்கள் பசியைத் தூண்டும் ஒரு நிஃப்டி ஸ்கிரீன்ஷாட் இதோ, "split(பிளவு)" பயன்முறையில் மூலத்தையும் அசெம்பிளியையும் காட்டுகிறது:

![](gdbwinss.png){border="0"}

இன்டெல் கணினிகளில் அசெம்பிளி குறியீடு இரண்டு வகைகளில் வருகிறது: Intel மற்றும் AT&T. பிரித்தெடுக்கும் சாளரத்தில் எது தோன்ற வேண்டும் என்பதை நீங்கள் `set disassembly-flavour` கொண்டு தேர்வு செய்யலாம். சரியான மதிப்புகள் "intel" மற்றும் "att" ஆகும். நீங்கள் ஏற்கனவே assembly சாளரத்தைத் திறந்திருந்தால், அதை மூடிவிட்டு மீண்டும் திறக்க வேண்டும் (உதாரணமாக, layout src யைத் தொடர்ந்து layout split.)

டம்ப் டெர்மினல் பயன்முறையில் பதிவேடுகளைக் காட்ட, முழு எண்(integer) பதிவேடுகளுக்கான `info registers` உள்ளிடவும் அல்லது எல்லாவற்றிற்கும் ஆன info all-registers ஐ உள்ளிடவும்.

[]{#frontend}

### ஒரு முன்னமைப்பை எழுதுதல் (Writing a FrontEnd)

நீங்கள் நினைக்கிறீர்கள், "ஆஹா, இது மிகவும் அருமையாக உள்ளது, ஆனால் இந்த விஷயத்திற்கு நான் அதை விட ஒரு பயங்கரமான முன்-முனையை எழுத முடியுமே, அது மிகவும் சிறப்பாக செயல்படுமே! நான் அதை எப்படி செய்வது?"

GDB ஆனது "இயந்திர இடைமுக மொழிபெயர்ப்பான்" (machine interface interprete) அல்லது GDB/MI என அழைக்கப்படுவதை ஆதரிக்கிறது. interpreter gdb கட்டளை வரியில் --interpreter சுவிட்ச் மூலம் தேர்ந்தெடுக்கப்பட்டுள்ளது.

அடிப்படையில் நீங்கள் gdb ஐ துவக்கி, கட்டளைகளையும் முடிவுகளையும் படிப்பீர்கள் (அநேகமாக குழாய்களைப்(pipes) பயன்படுத்தி இருக்கலாம்). அழகான நேரடியான ஒன்று.

அனைத்து விவரங்களுக்கும் [GDB ஆவணங்களைப்](http://sourceware.org/gdb/current/onlinedocs/gdb_26.html#SEC263) பார்க்கவும்.

[]{#qref}

### விரைவான குறிப்பு (Quick Reference)

இந்தப் பட்டியல் மிகவும் முழுமையடையாதது, மேலும் இந்த டுடோரியலில் பேசப்பட்ட விஷயங்களை மட்டுமே காட்டுகிறது!

இங்கே [சொடுக்கவும்](https://beej.us/guide/bggdb/#qref) 


