Dir["#{File.expand_path("../support", __FILE__)}/**/*.rb"].each { |f| require f }

RSpec.configure do |config|
  config.include CompileAndRun
  config.include RpnCalculator
end
