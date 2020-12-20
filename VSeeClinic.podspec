#
# Be sure to run `s.ios.dependency lib lint VSeeClinic.s.ios.dependencyspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a s.ios.dependencyspec see https://guides.cocoas.ios.dependencys.org/syntax/s.ios.dependencyspec.html
#

Pod::Spec.new do |s|
  
  s.name             = 'VSeeClinic'
  s.version          = '1.17.0'
  s.summary          = 'VSeeClinic SDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, Cocoas.ios.dependencys strips it!

   s.description = "Provide easy-to-use APIs for developers to access VSeeClinic API"
   

  s.homepage         = 'https://github.com/dhduongt3@gmail.com/VSeeClinic'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'dev@vsee.com' => 'dev@vsee.com' }
  s.source           = { :git => 'https://github.com/dhduongt3@gmail.com/VSeeClinic.git', :tag => s.version.to_s }
  
  s.vendored_frameworks   = "VSeeClinicKit.framework"
  s.ios.deployment_target = '11.0'
  s.platform              = :ios
  s.swift_version         = "4.2"

  s.source_files = 'VSeeClinic/Assets/**/*'
  
  # s.resource_bundles = {
  #   'VSeeClinic' => ['VSeeClinic/Assets/*.png']
  # }

  s.public_header_files = 'VSeeClinic/Assets/VSeeClinicKit.framework/Headers/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.ios.dependency 'AFNetworking', '~> 4.0'
  s.ios.dependency 'MagicalRecord', '2.3.2'
  s.ios.dependency 'SDWebImage', '~> 4.4.2'
  s.ios.dependency 'MBProgressHUD', '~> 1.0.0'
  s.ios.dependency 'UICKeyChainStore', '~> 2.1.0'
  s.ios.dependency 'FontAwesomeKit', '~> 2.2.0'
  s.ios.dependency 'GBDeviceInfo', '~> 4.2.2'
  s.ios.dependency 'Charts', '~> 3.2.1'
  s.ios.dependency 'XLPagerTabStrip', '~> 8.1.0'
  
  #use_frameworks!
  s.ios.dependency 'Eureka', '~> 5.2.1'
  s.ios.dependency 'ImagePicker'
  s.ios.dependency 'HCSStarRatingView', '~> 1.4.5'
  s.ios.dependency 'Whisper', '~> 6.0.2'
  s.ios.dependency 'FSCalendar', '~> 2.7.9'
  s.ios.dependency 'Stripe', '~> 9.4.0'
  s.ios.dependency 'TTTAttributedLabel', '~> 2.0.0'
  s.ios.dependency 'SearchTextField', '1.2.0'
  
end
