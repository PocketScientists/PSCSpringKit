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
 * </table>

 <p>Considering that the Apple private policy is changing all the time, Spring libs have to adapt different UDIDs for identifying the end user's devices.</p>
 <p>
 -# Since iOS 6, device ID and mac ID are not available anymore,
 -# Switch to Advertising ID and ID_For_Vendor</p>
 
 <p><i>Please attention: Apple will reject all the applications which retrieve advertising ID but with no advertising content provided. So Advertising-Framework is linked as optional in Spring libs, If the Advertising ID should be used as udid, please import Advertising-Framework into your projects.</i></p>
 
 <h3>NOTICE</h3>
 <p><i>Please Note: Some components in Spring libs are running in background threads. Please keep the initialization and usage of Spring libs in your main thread, Spring libs will not block your UI display.
</i></p>
 <h1>  </h1><h1>  </h1>
 <div align="center">
  <h1><a href="ReleaseNote.html">****RELEASE NOTE****</a></h1>
 </div>




 */
