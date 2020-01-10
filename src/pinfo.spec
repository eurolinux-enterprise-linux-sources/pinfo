Summary:	Lynx-style info browser
Summary(pl):	Prz�gl�darka info w stylu lynksa
Summary(ru):	����� info-������ ��������
Name:		pinfo	
Version:	0.6.9
Release:	1
Group:		Utilities/System
Group(pl):	Narz�dzia/System
Group(ru):	�������/�������
Copyright:	GPL
Vendor:		Bas Zoetekouw <bas@debian.org>
Source:		http://alioth.debian.org/project/showfiles.php?group_id=30592
BuildRoot:   	/tmp/%{name}-%{version}-root

%define		_prefix		/usr
%define		_sysconfdir	/etc
%define		_datedir	%{_prefix}/share
%define		_bindir		%{_prefix}/bin
%define		_mandir		%(if [ "%{_target_vendor}" == "pld" ]; then echo "%{_prefix}/share/man"; else echo "%{_prefix}/share/man"; fi) 

%description
Pinfo is a curses based lynx-style info browser.

%description -l pl
Pinfo jest przegl�dark� dokument�w info podobn� do lynksa.

%description -l ru
�������������� ����� info-������. ���������������� ��������� ����������
lynx'�. ���������� �� ncurses. ����� ����� �������� � man-����������. 
������������ regexp-�����.

%prep
echo "%{_mandir}"
%setup -q

%build
LDFLAGS="-s"; export LDFLAGS
%configure \
	--without-included-gettext 
	
make 

%install
rm -rf $RPM_BUILD_ROOT

make install DESTDIR=$RPM_BUILD_ROOT

gzip -9nf $RPM_BUILD_ROOT%{_mandir}/man*/* \
	ChangeLog NEWS AUTHORS README

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(644,root,root,755)
%doc *.gz
%attr(755,root,root) %{_bindir}/pinfo
%config %verify(not md5 size mtime) %{_sysconfdir}/pinforc

%lang(pl) %{_datadir}/locale/pl/LC_MESSAGES/*
%lang(cs) %{_datadir}/locale/cs/LC_MESSAGES/*
%lang(de) %{_datadir}/locale/de/LC_MESSAGES/*
%lang(sv) %{_datadir}/locale/sv/LC_MESSAGES/*
%lang(ru) %{_datadir}/locale/ru/LC_MESSAGES/*
%{_mandir}/man1/*

%changelog
* Mon May  3 1999 Artur Frysiak <wiget@pld.org.pl>
  [0.5.2-1]
- added de and sv locale

* Fri Apr 16 1999 Artur Frysiak <wiget@pld.org.pl>
  [0.4.9-1]
- added --with-readline to ./configure
- added pinforc and polish locale to %%files

* Sat Apr 10 1999 Artur Frysiak <wiget@pld.org.pl>
  [0.4.8-1]
- added --sysconfdir=/etc to ./configure

* Thu Mar 25 1999 Tomasz K�oczko <kloczek@rudy.mif.pg.gda.pl>
  [0.3.5-1]
- fixed passing $RPM_OPT_FLAGS.

* Mon Mar 23 1999 Micha� Kuratczyk <kura@pld.org.pl>
  [0.3.1-1]
- upgraded to 0.3.1

* Sun Mar 21 1999 Micha� Kuratczyk <kura@pld.org.pl>
  [0.2.4-1]
- upgraded to 0.2.4

* Fri Mar 19 1999 Micha� Kuratczyk <kura@pld.org.pl>
  [0.2.3-1]
- initial RPM release
