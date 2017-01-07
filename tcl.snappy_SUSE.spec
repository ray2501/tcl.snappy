%{!?directory:%define directory /usr}

%define buildroot %{_tmppath}/%{name}

Name:          tcl.snappy
Summary:       snappy wrapper for Tcl
Version:       0.3
Release:       2
License:       2-Clause BSD license
Group:         Development/Libraries/Tcl
Source:        https://sites.google.com/site/ray2501/tcl-snappy/tcl.snappy_0.3.zip
URL:           https://sites.google.com/site/ray2501/tcl-snappy
Buildrequires: tcl >= 8.4
BuildRoot:     %{buildroot}

%description
snappy wrapper for Tcl.

Snappy is a compression/decompression library. It does not aim for maximum
compression, or compatibility with any other compression library; instead,
it aims for very high speeds and reasonable compression.

%prep
%setup -q -n %{name}

%build
export CC=g++
./configure \
	--prefix=%{directory} \
	--exec-prefix=%{directory} \
	--libdir=%{directory}/%{_lib}
make 

%install
make DESTDIR=%{buildroot} pkglibdir=%{directory}/%{_lib}/tcl/%{name}%{version} install

%clean
rm -rf %buildroot

%files
%defattr(-,root,root)
%{directory}/%{_lib}/tcl
