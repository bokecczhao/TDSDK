

Pod::Spec.new do |s|


  s.name         = "TDSDK"
  s.version      = '4.1.0'
  s.summary      = "An iOS SDK for LiveTD"

  s.description  = <<-DESC
	It's  an iOS SDK TD.
                   DESC
  s.homepage     = "https://github.com/bokecczhao/TDSDK"

  s.license      = 'Apache License, Version 2.0'

  s.author             = { "Zhao" => "zhaox@bokecc.com" }

  s.platform     = :ios, "10.0"


  s.source       = { :git => "https://github.com/bokecczhao/TDSDK.git", :tag => s.version.to_s }
  s.vendored_frameworks = 'SDK/*.{framework}'
  s.resource = 'SDK/CCBundle.bundle'
  s.dependency 'HDBaseUtils'

end
