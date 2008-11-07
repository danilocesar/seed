#!/usr/local/bin/seed
// Returns: 0
// STDIN:
// STDOUT:In klass init\nIn constructor for \[object HelloWindow\]\nPrototypes!\nIn map, verifying widget\.title : Hello!
// STDERR:

Seed.import_namespace("Gtk");
Gtk.init(null, null);

HelloWindowType = {
    parent: Gtk.Window,
    name: "HelloWindow",
    class_init: function(klass, prototype)
    {
	prototype.message = "Prototypes!";
	Seed.print("In klass init");
    },
    instance_init: function(widget, klass)
    {
	widget.title = "Hello!";
	Seed.print("In constructor for " + widget);
    }};

HelloWindow = new GType(HelloWindowType);
w = new HelloWindow();
Seed.print(w.message);
w.signal.map.connect(
		     function(widget)
		     {
			 Seed.print("In map, verifying widget.title : " 
				    + widget.title)
		     });
w.show();
	  