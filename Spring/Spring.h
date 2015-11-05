/*
 * (c) Copyright 2000-2011 spring saarlouis
 * All Rights Reserved.
 * 
 * contact info@spring.de for more information
 */



/**
 * Static tags of the application status
 */
extern NSString *const SPRING_VAR_ACTION;
extern NSString *const SPRING_APP_STARTED;
extern NSString *const SPRING_APP_FOREGROUND;
extern NSString *const SPRING_APP_BACKGROUND;
extern NSString *const SPRING_APP_CLOSED;


@interface Spring : NSObject {
}
    
/** Enable or disable usage tracking. (default: true) */
@property(nonatomic, getter=isTracking) BOOL tracking;
    
/**
 * When set to true (default:false) the library logs the internal actions.
 * Each error is logged without checking this property.
 */
@property(nonatomic) BOOL debug;


/**
 * Enable or disable offline mode. It will be configured in the release process. 
 * Please refer to main page for more info about offlineMode
 */
@property(nonatomic) BOOL offlineMode;
/**
 * Internally it sends http requests to the measurement system.
 * This property sets a timeout for that purpose.
 */
@property(assign) NSTimeInterval timeout;

/**
 * return the instance of spring lib, in id type
 * Initialization of the spring library, with a site name and an application name
 * @warning
 *   The site name and the application name should be provided accrodingly
 */
- (id)initWithSiteAndApplication:(NSString *)theSite application:(NSString *)theApplication;

/**
 * Commit gathered data to server when application status changes.
 * Initialization of the spring library, with a site name and an application name
 * @throws An exception is thrown when connection problem occurs.
*/
- (void)commit:(NSDictionary *)theDictionary;
	
@end


/**
 * @mainpage
 
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
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;string&gt;<span class="marker"><span style="color:#0000CD;">@oldPanelApp</span>&lt;</span>/string&gt;
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;string&gt;<span style="color:#0000CD;"><span class="marker">@newPanelApp</span></span>&lt;/string&gt;
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
 <br>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&lt;key&gt;<span style="color:#0000CD;">@domain</span>&lt;/key&gt;
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
 
 <p><i>Please attention: Only initialize Spring lib once in your whole project, you only need one Spring object.</i></p>
 
 
 
 
 <h3>NOTICE</h3>
 <p><i>Please Note: Some components in Spring libs are running in background threads. Please keep the initialization and usage of Spring libs in your main thread, Spring libs will not block your UI display.
</i></p>
 <h1>  </h1><h1>  </h1>
 <div align="center">
  <h1><a href="ReleaseNote.html">****RELEASE NOTE****</a></h1>
 </div>




 */
