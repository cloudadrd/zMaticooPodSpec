#
# Be sure to run `pod lib lint zMaticoo.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'zMaticoo'
  s.version          = '1.5.4.3'
  s.summary          = 'zMaticoo iOS SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  zMaticoo iOS SDK CocoaPods Spec
                       DESC
                       
  s.homepage         = 'https://www.zmaticoo.com'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'tianwenshi' => '100345612@qq.com' }
  s.source           = { :git => 'https://github.com/cloudadrd/zMaticooPodSpec.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '11.0'
  s.ios.vendored_frameworks = 'MaticooSDK/Frameworks/MaticooSDK.xcframework'
  s.ios.library = 'z'
#  s.source_files = 'zMaticoo/Classes/**/*'
  
  # s.resource_bundles = {
  #   'zMaticoo' => ['zMaticoo/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
