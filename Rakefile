require 'bundler'
Bundler.setup

require 'rake'
require 'rake/extensiontask'
require 'rubygems/package_task'
require 'rspec/core/rake_task'

gem = Gem::Specification.load( File.dirname(__FILE__) + '/proc_compose.gemspec' )
Rake::ExtensionTask.new( 'proc_compose', gem )

Gem::PackageTask.new gem  do |pkg|
    pkg.need_zip = pkg.need_tar = false
end

RSpec::Core::RakeTask.new :spec

task :default => [:compile, :spec]
