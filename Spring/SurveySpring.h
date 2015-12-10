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



<h3>SurveySpring Lib</h3>
 
 <div align="center">
 <h2>iOS-Spring-lib User Manual</h2>
 </div>
 
 
 <div style="background-color: grey;" >
 <div align="center">
 <h3>Migration to iOS 9 </h3>
 </div>
 
 <h3>URL Scheme</h3>
 <p>Starting on iOS 9, iOS apps will have to declare what URL schemes they would like to be able to check for and open in the configuration files (plist file) of the app as it is submitted to Apple. So if your application is combining with a specific "Panel App" (e.g. Virtualmeter App), please register the URL scheme in your application, the syntax is as following:</p>
 
 <div style="border:1px solid black;">
 <br>&lt;key&gt;LSApplicationQueriesSchemes&lt;/key&gt;
 <br>&nbsp;&nbsp; &nbsp;&lt;array&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;string&gt;<span class="marker"><span style="color:#0000CD;">oewaPanelApp</span>&lt;</span>/string&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;string&gt;<span style="color:#0000CD;"><span class="marker">at.tns.ipm</span></span>&lt;/string&gt;
 <br>&nbsp;&nbsp; &nbsp;&lt;/array&gt;</div>
 
 
 <h3>App Transport Security (ATS)</h3>
 <p>Starting from iOS 9.0, App Transport Security (ATS) enforces best practices in the secure connections between an app and its back end. Migrating from http to https has to be planed for the more secure communication. However for this moment, if you decide to enable ATS, a temporary solution can be adapted by adding an exception for Kantar Media Audiences measurement box: </p>
 
 <div style="border:1px solid black;">
 &lt;key&gt;NSAppTransportSecurity&lt;/key&gt;
 <br>&lt;dict&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;key&gt;NSAllowsArbitraryLoads&lt;/key&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;false/&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;key&gt;NSExceptionDomains&lt;/key&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;dict&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;key&gt;<span style="color:#0000CD;">oewabox.at</span>&lt;/key&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;dict&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;key&gt;NSIncludesSubdomains&lt;/key&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;true/&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;key&gt;NSTemporaryExceptionAllowsInsecureHTTPLoads&lt;/key&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;true/&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;key&gt;NSExceptionRequiresForwardSecrecy&lt;/key&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;false/&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;/dict&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;/dict&gt;
 <br>&nbsp;&nbsp; &nbsp;&lt;/dict&gt;</div>
 <p><i><span class="marker"><span style="color:#0000CD;">if</span></span> ATS is not enabled in your application, as NSAllowsArbitraryLoads = true, then you don't need to modify anything.
 </i></p>
 
 <h3>BitCode</h3>
 <p>Bitcode is a new feature on iOS 9, an intermediate representation of a compiled program. Now you have the new Spring lib with bitcode enabled, for your application you have the chance to enable or disable the bitcode service.</p>
 </div>
 
 
 
 
 
<p>SurveySpring lib is an extension to the Spring lib. It offers you the opportunity to achieve the on-line questionary with the end users. The SurveySpring lib will trigger the on-line questionary in device default browser if the device is chosen to be the participant and of course with the acceptance from the end user.</p>
 
 <h3>How to register</h3>
 
 
 <p>Due to the fact that the questionary is not mandatory for every app users, the sample is chosen randomly by the QDS server. So for test purpose, you need to first register your device into Spring QDS server, otherwise in most of the cases, questionary will be not present. For registration, please download the registration app by following the link:</p></p><p><a href="https://confluence.spring.de/x/ooCaAQ">Registration App</a></p>
 


<h3>How to use SurveySpring</h3>


<p>SurveySpring is easy-to-use. Please import the necessary attached lib files into your project, SurveySpring.h, Spring.h and bundle resources are mandatory, you are free to choose the lib file based on your deploy environment, fat.a is recommended. If you need the survey service, just initialize a SurveySpring object, SurveySpring will do the rest for you. SurveySpring lib will communicate with Kantar Media QDS server and trigger the participation dialog if the device is randomly chosen for the questionary. End user has the chance to fill out the questionary or delay it, once the user decide to participate, SurveySpring lib will lead the user to the default browser with the questionary site open. The questionary site is also monitored by Spring measurement plug-in, waypoint info will be gathered during the process. </p>
 
<p>After the questionary, system will switch the application back to foreground if the 'URL Scheme' is registered in the application. Please notice, the url scheme registered in the application <span style="background-color: #FFFF00">must</span> match the lower case of "application name" in SurveySpring object. If the application name is "MyApp", the url scheme should be "myapp", no spaces in between. About how to register the url-scheme, please refer to:</p><a href="http://iosdevelopertips.com/cocoa/launching-your-own-application-via-a-custom-url-scheme.html">The Complete Tutorial on iOS/iPhone Custom URL Schemes</a>
<p>SurveySpring is an extension to the Spring Tagging lib, so the functionalities of the Spring lib is also available in SurveySpring lib with the same behaviours.
 More info about Spirng lib can be found here:</p><p><a href="https://confluence.spring.de/display/public/Implementation+iOS">Spring Tagging Library</a></p>

<h3>NOTICE</h3>
<p><i>Please Note: SurveySpring will extract 'Advertising ID' as the only identifier, please import AdsupportFramework into your project </i></p>
 <p><i>Please attention: Only initialize SurveySpring lib once in your whole project, you only need one SurveySpring object.</i></p>


<p><i>
Some components in Spring libs are running in background threads. Please keep the initialization and usage of Spring libs in your main thread, Spring libs will not block your UI display.
</i></p>
 
 <div align="center">
 <h2>iOS-Spring-lib</h2>
 </div>
 <h3>Offline Mode</h3>
 <p>iOS-Spring-lib has feature so called "offlineMode". This mode can be switched on and off by using public API: Spring.offlineMode.
 If the lib is configured to offlineMode, Spring library will hold all requests in a local buffer and send them when the device goes back online. Spring lib checks the Internet connection regularly by using the iOS Timer and send the data as soon as possible.
 Please notice:
 -# Old requests will be dropped if too many requests pump into local buffer for the limitation in buffer size. The default buffer size is 500. The data will be stored in a local file, so the lib will not lose the requests even if the application terminates.
 -# Spring lib tries to send the requests in a fixed rate, 10 seconds by default, and sends them if device is online.</p>
 
 <h3>UDID</h3>
 * <table>
 * <tr><th> </th><th>Device ID(did)</th><th>Advertising ID(ai)</th><th>MAC ID(mid)</th><th>ID_For_Vendor(ifv)</th></tr>
 
 <tr><td>iOS 4</td><td><div align="center">---</div></td><td><div align="center">---</div></td><td>MAC ID(mid)</td><td><div align="center">---</div></td></tr>
 <tr><td>iOS 5</td><td><div align="center">---</div></td><td><div align="center">---</div></td><td>MAC ID(mid)</td><td><div align="center">---</div></td></tr>
 <tr><td>iOS 6</td><td><div align="center">---</div></td><td>Advertising ID(ai)</td><td>MAC ID(mid)</td><td>ID_For_Vendor(ifv)</td></tr>
 <tr><td>iOS 7</td><td><div align="center">---</div></td><td>Advertising ID(ai)</td><td><div align="center">---</div></td><td>ID_For_Vendor(ifv)</td></tr>
 <tr><td>iOS 8</td><td><div align="center">---</div></td><td>Advertising ID(ai)</td><td><div align="center">---</div></td><td>ID_For_Vendor(ifv)</td></tr>
 <tr><td>iOS 9</td><td><div align="center">---</div></td><td>Advertising ID(ai)</td><td><div align="center">---</div></td><td>ID_For_Vendor(ifv)</td></tr>
 * </table>
 
 <p>Considering that the Apple private policy is changing all the time, Spring libs have to adapt different UDIDs for identifying the end user's devices.</p>
 <p>
 -# Since iOS 6, device ID and mac ID are not available anymore,
 -# Switch to Advertising ID and ID_For_Vendor</p>
 
 <p><i>Please attention: Apple will reject all the applications which retrieve advertising ID but with no advertising content provided. So Advertising-Framework is linked as optional in Spring libs, If the Advertising ID should be used as udid, please import Advertising-Framework into your projects.</i></p>
  <p><i>Please attention: Only initialize SurveySpring lib once in your whole project, you only need one SurveySpring object.</i></p>
 
 
 
 
 <h3>NOTICE</h3>
 <p><i>Please Note: Some components in Spring libs are running in background threads. Please keep the initialization and usage of Spring libs in your main thread, Spring libs will not block your UI display.
  <p><i>Please attention: Only initialize Spring lib once in your whole project, you only need one Spring object.</i></p>
 </i></p>
 <h1>  </h1><h1>  </h1>
 <div align="center">
 <h1><a href="ReleaseNote.html">****RELEASE NOTE****</a></h1>
 </div>

*/