//
//  SurveySpring.h
//  Spring
//
//  Created by Tony on 4/2/15.
//
//

#import "Spring.h"


@interface SurveySpring : Spring

- (id)initWithSiteAndApplication:(NSString *)theSite application:(NSString *)theApplication;
- (BOOL) isTracking;
- (void) setTracking:(BOOL) tracking;

- (void) setDebug:(BOOL)debug;
@end

/**
@mainpage



<div align="center">
<h2>iOS-SurveySpring-lib User Manual</h2>
</div>



<h3>SpringSurvey Lib</h3>
<p>SurveySpring lib is an extension to the Spring lib. It offers you the opportunity to achieve the on-line questionary with the end users. The SpringSurvey lib will trigger the on-line questionary in device default browser if the device is chosen to be the participant and of course with the acceptance from the end user.</p>
 
 <h3>How to register</h3>
 
 
 <p>Due to the fact that the questionary is not mandatory for every app users, the sample is chosen randomly by the QDS server. So for test purpose, you need to first register your device into Spring QDS server, otherwise in most of the cases, questionary will be not present. For registration, please download the registration app by following the link:</p></p><p><a href="https://confluence.spring.de/x/ooCaAQ">Registration App</a></p>
 


<h3>How to use SurveySpring</h3>


<p>SurveySpring is easy-to-use. Please import the necessary attached lib files into your project, SurveySpring.h, Spring.h and bundle resources are mandatory, you are free to choose the lib file based on your deploy environment, fat.a is recommended. If you need the survey service, just initialize a SurveySpring object, SurveySpring will do the rest for you. SurveySpring lib will communicate with Kantar Media QDS server and trigger the participation dialog if the device is randomly chosen for the questionary. End user has the chance to fill out the questionary or delay it, once the user decide to participate, SurveySpring lib will lead the user to the default browser with the questionary site open. The questionary site is also monitored by Spring measurement plug-in, waypoint info will be gathered during the process. </p>
 
<p>After the questionary, system will switch the application back to foreground if the 'URL Scheme' is registered in the application. Please notice, the url scheme registered in the application <span style="background-color: #FFFF00">must</span> match the lower case of "application name" in SurveySpring object. If the application name is "MyApp", the url scheme should be "myapp", no spaces in between. About how to register the url-scheme, please refer to:</p><a href="http://iosdevelopertips.com/cocoa/launching-your-own-application-via-a-custom-url-scheme.html">The Complete Tutorial on iOS/iPhone Custom URL Schemes</a>
<p>SurveySpring is an extension to the Spring Tagging lib, so the functionalities of the Spring lib is also available in SurveySpring lib with the same behaviours.
 More info about Spirng lib can be found here:</p><p><a href="https://confluence.spring.de/display/public/Implementation+iOS">Spring Tagging Library</a></p>

<h3>NOTICE</h3>
<p><i>Please Note: SurveySpring will extract 'Advertising ID' as the only identifier, please import AdsupportFramework into your project </i></p>


<p><i>
Some components in Spring libs are running in background threads. Please keep the initialization and usage of Spring libs in your main thread, Spring libs will not block your UI display.
</i></p>

<div align="center">
<h1><a href="ReleaseNote.html">****RELEASE NOTE****</a></h1>
</div>

*/