# prependpath

Given a (PATH-like) colon-separated string - this tool prepends a value to the string.

Importantly, prependpath is idempotent because it removes existing duplicates of the value in the string.

## Usage
```sh
prependpath [value] [colon-separated-values]
```

## Example
```sh
export PATH=$(prependpath "/my/path/bin" "$PATH")
```

## Install
```sh
# Build using the default C compiler
cc prependpath.c -o prependpath -O2 -Wall -Wextra

# Install to /usr/local/bin
sudo cp prependpath /usr/local/bin/prependpath
```


## FAQ
How is this different from just doing the following?
```sh
export PATH="/my/path/bin:$PATH"
```

If `/my/path/bin` already exists in PATH, it will be removed so that the entry is not duplicated. This makes it convenient for usage in `~/.zshrc` or `~/.bashrc` as it avoids ever-growing PATH-variables when nesting shells.
