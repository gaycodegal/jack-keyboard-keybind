# Things to do, eventually

-   Jack-keyboard does strange things to input focus and keyboard event
   handling.  Verify that it does not cause any problems.
    -   Focus grabbing doesn't work really, investigate whether that can
    	be improved.

-   Make the code cleaner.  Get rid of all these global variables etc.
    -   Taken as: Convert to C++

-   Tooltips.

-   Fix language (english) errors in documentation and web page.

-   [50%] Add user-configurable key binding.
    -   Completed basic map for midi
    -   Need to address function key-binding
    -   Keybind to [OSC][OSC] message, to allow control over DAWS + plugins
    	that use the format

-   Allow instrument selection via [OSC][OSC] so we can automatically
    select the same instrument(s) as the daw

-   Command line arguments for file path configuration, perhaps
    a verbosity toggle?


[OSC]: https://en.wikipedia.org/wiki/Open_Sound_Control
