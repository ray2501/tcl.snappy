%{!?directory:%define directory /usr}

%define buildroot %{_tmppath}/%{name}

Name:          tcl.snappy
Summary:       snappy wrapper for Tcl
Version:       0.5
Release:       1
License:       2-Clause BSD license
Group:         Development/Libraries/Tcl
Source:        https://sites.google.com/site/ray2501/tcl-snappy/tcl.snappy_0.5.zip
URL:           https://sites.google.com/site/ray2501/tcl-snappy
BuildRequires: autoconf
BuildRequires: make
BuildRequires: tcl-devel >= 8.4
Requires:      tcl >= 8.4
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
