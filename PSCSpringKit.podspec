Pod::Spec.new do |s|
  s.platform     = :ios, '6.0'
  s.name         = 'PSCSpringKit'
  s.version      = '1.8.12'
  s.license      = ''
  s.summary      = ''
  s.homepage     = 'http://www.nousguide.com/de/'
  s.authors      = 'NOUS Guide GmbH.'
  s.summary      = 'Easy to use API for Spring Mobile App Sensor (aka ÖWA Mobile App Sensor)'
  s.source       = { :git => 'https://github.com/PocketScientists/PSCSpringKit.git' }
  s.source_files = 'PSCSpringKit/PSCSpringKit/*.{h,m}', 'Spring/*{h,m}'
  s.library = 'springappsensorfat'
  s.preserve_paths = 'Spring/libspringappsensorfat.a'
  s.ios.vendored_library = 'Spring/libspringappsensorfat.a'
  s.prepare_command  = <<-CMD
                          cp $PWD/Spring/spring-appsensor-fat.a $PWD/Spring/libspringappsensorfat.a
                          CMD

  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/**"'}
  s.requires_arc = true
  s.prefix_header_contents = '
#ifdef __OBJC__
    #import <Foundation/Foundation.h>
    #import "Spring.h"
#endif'
end
