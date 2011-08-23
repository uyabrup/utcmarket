Drupal.behaviors.jqzoomBehavior = function(context) {	

var options = {
                         zoomWidth: 300,
                         zoomHeight: 300,
                         zoomType:'reverse',
						 showEffect:'show',
                         hideEffect:'fadeout',
                         fadeoutSpeed: 'fast',
						 preloadText: '',
                      }

            $("#zoom-link").jqzoom(options);

};

/*

�������� ���������               �� ���������                ��������

zoomType                         'standard'                        ��� �����, ����� ���� �����  'reverse'.     
zoomWidth                        200                                  ������ ���-��� � ����������� ������������.
zoomHeight                       200                                  ������ ���-��� � ����������� ������������.
xOffset                          10                                    ������ ���-��� � ����������� ������������ �� ��������� �������� �� �����������.���������� �������� ��� ������� right/left � ����������/���������� ��� ������� top/bottom.
yOffset                          0                                      ������ ���-��� � ����������� ������������. ������ ���������� �������� ��� ������� 'right/left', ������ ���������� ��� ������� 'top/bottom'.
position                         'right'                                ������� ���-���. ���������� ��������:'right' ,'left' ,'top' ,'bottom'
lens                             true                                  ���� ����������� � false, ����� �� ����� ��������.
imageOpacity                     0.2                                    ������������ ���������, ����  'zoomType' ����������� � 'reverse'.
title                            true                                  ������� ��� ������������ (������ �� ���� title).
showEffect                       'show'                              ������ ������ ���-���. ��������: 'show' ,'fadein'.
hideEffect                       'hide'                               ������ �������� ���-���. ��������: 'hide' ,'fadeout'.
fadeinSpeed                      'fast'                                �������� ���������, ���� showEffect ����������� � 'fadein'. ��������: 'fast','slow','medium')
fadeoutSpeed                     'slow'                               �������� ��������� ���-���, ���� hideEffect ����������� �  'fadeout'. ��������: 'fast','slow','medium')
showPreload                      true                                 ����� ���������� ��������. ��������: 'true','false')
preloadText                      'Loading zoom'                ����� ���������� ��������.
preloadPosition                  'center'                            ������� ���������� ��������.

*/


