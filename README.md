# Proc#compose

This gem does just one thing: it adds `compose` to `Proc`, with the alias `*`. Based on [this experiment](https://github.com/mooreniemi/compose).

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'proc_compose'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install proc_compose

## Usage

Given two `Proc`s, say:

```ruby
double = proc {|a| a * 2 }
triple = proc {|a| a * 3 }
```

Allow composition:

```ruby
(double * triple).(2)
=> 12
```

So you can do things like this:

```ruby
[1, 2, 3, 4, 5].map(&(double * triple))
=> [6, 12, 18, 24, 30]
```

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/mooreniemi/proc_compose. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [Contributor Covenant](http://contributor-covenant.org) code of conduct.


## License

The gem is available as open source under the terms of the [MIT License](http://opensource.org/licenses/MIT).

