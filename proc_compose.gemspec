# coding: utf-8

Gem::Specification.new do |spec|
  spec.name          = 'proc_compose'
  spec.version       = '0.0.1'
  spec.authors       = ['Alex Moore-Niemi']
  spec.email         = ['moore.niemi@gmail.com']

  spec.summary       = %q{ Proc#compose (*) C extension }
  spec.homepage      = 'https://github.com/mooreniemi/proc_compose'
  spec.license       = 'MIT'

  spec.extensions    = ['ext/proc_compose/extconf.rb']
  spec.require_paths = ['lib']
  spec.files         = [
    'LICENSE.txt',
    'README.md',
    'lib/.gemkeep',
    'ext/proc_compose/extconf.rb',
    'ext/proc_compose/proc_compose.c',
  ]
  spec.test_files = Dir['spec/**/*_spec.rb']

  spec.add_development_dependency 'bundler', '~> 1.12'
  spec.add_development_dependency 'rake', '~> 10.0'
  spec.add_development_dependency 'rake-compiler'
  spec.add_development_dependency 'rspec', '~> 3.0'
  spec.add_development_dependency 'pry'
end
